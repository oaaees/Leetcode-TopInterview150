#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for( int i = cost.size() - 3; i >= 0; i--){
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }

        return min(cost[0], cost[1]);
    }

    int min (int a, int b){
        if (a < b){
            return a;
        } else {
            return b;
        }
    }
};

int main (){
    Solution sol;
    vector<int> cost = {0,2,2,1};
    cout << sol.minCostClimbingStairs(cost);

    return 0;
}