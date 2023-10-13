#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sum = 0;
        int n = cost.size();
        int last_index = n;

        while (last_index > 1){
            if( cost[last_index - 2] > cost[last_index - 1] ){
                sum += cost[last_index - 1];
                last_index -= 1;
            } else {
                sum += cost[last_index - 2];
                last_index -= 2;
            }
        }

        return sum;
    }
};

int main (){
    Solution sol;
    vector<int> cost = {0,2,2,1};
    cout << sol.minCostClimbingStairs(cost);

    return 0;
}