#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b){
            int a1 = count_ones(a);
            int b1 = count_ones(b);
            
            if(a1 == b1){
                return a < b;
            } else {
                return a1 < b1;
            }
        });

        return arr;
    }
    int count_ones(int a){
        int count = 0;
        while(a != 0){
            if(a % 2){ count++; }
            a = a >> 1;
        }
        return count;
    }
};

int main (){
    Solution sol;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> sorted = sol.sortByBits(arr);
    
    for(int x : sorted){
        cout << x << " ";
    }

    return 0;
}