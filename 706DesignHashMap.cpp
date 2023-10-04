#include <vector>
#include <iostream>
using namespace std;

class MyHashMap {
private:
    int n;
    vector<vector<vector<int>>> map;
public:
    MyHashMap() {
        n = 10;
        map = vector<vector<vector<int>>>(n, vector<vector<int>>(0, vector<int>(2, 0)));
    }
    
    void put(int key, int value) {
        int bucket = key % n;

        for(int i = 0; i < map[bucket].size(); i++){
            if(key == map[bucket][i][0]){
                map[bucket][i][1] = value;
                return;
            }
        }

        map[bucket].push_back({key, value});
        return;
    }
    
    int get(int key) {
        int bucket = key % n;

        for(int i = 0; i < map[bucket].size(); i++){
            if(key == map[bucket][i][0]){
                return map[bucket][i][1];
            }
        } 

        return -1;
    }
    
    void remove(int key) {
        int bucket = key % n;

        for(int i = 0; i < map[bucket].size(); i++){
            if(key == map[bucket][i][0]){
                map[bucket].erase(map[bucket].begin() + i);
                return;
            }
        }    

        return;
    }
};

int main (){
    MyHashMap* obj = new MyHashMap();
    obj->put(1,1);
    int param_2 = obj->get(1);
    obj->remove(1);

    return 0;
}


