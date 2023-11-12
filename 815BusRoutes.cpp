#include <vector>
#include <iostream>
using namespace std;

struct Bus {
    bool visited;
    vector<int> route;
    vector<Bus *> next;
    Bus(vector<int> _route){
        route = _route;
        next = {};
        visited = false;
    }
};

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<Bus> Buses;

        // Create Graph
        for(vector<int> route : routes){
            Buses.push_back(Bus(route));
            for(int i = Buses.size() - 2; i >= 0; i--){
                for(int j = 0; j < Buses[i].route.size(); j++){
                    for(int k = 0; k < Buses[Buses.size() - 1].route.size(); k++){
                        if(Buses[Buses.size() - 1].route[k] == Buses[i].route[j]){
                            Buses[i].next.push_back(&Buses[Buses.size() - 1]);
                            Buses[Buses.size() - 1].next.push_back(&Buses[i]);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < Buses.size(); i++){
            for(int j = 0; j < Buses[i].route.size(); j++){
                if(Buses[i].route[j] == source){
                    return BFS(&Buses[i], target);
                }
            }
        }

        return -2;
    }
    int BFS(Bus * source, int target){
        int count = 0;
        vector<Bus *> to_visit = { source };

        while(!to_visit.empty()){
            vector<Bus *> next_to_visit = {};

            for(int i = 0; i < to_visit.size(); i++){
                to_visit[i]->visited = true;
                for(int j = 0; j < to_visit[i]->route.size(); j++){
                    if(to_visit[i]->route[j] == target) return count;
                }
                for(int j = 0; j < to_visit[i]->next.size(); j++){
                    if(!to_visit[i]->next[j]->visited) next_to_visit.push_back(to_visit[i]->next[j]);
                }
                count++;
                to_visit = next_to_visit;
            }
        }

        return -1;
    }
};

int main (){
    Solution sol;
    vector<vector<int>> routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    cout << sol.numBusesToDestination(routes, 15, 12);
    return 0;
}