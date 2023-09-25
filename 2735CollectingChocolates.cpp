#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int imin = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[imin]) imin = i;
        }
        
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(x + nums[imin] < nums[i]){
                sum += (x + nums[imin]);
            } else {
                sum += nums[i];
            }
        }

        return sum;
    }
};

int main () {
    Solution sol;
    vector<int> nums = {15,150,56,69,214,203};
    int x = 42;

    cout << "Min cost is: " << sol.minCost(nums, x);

    return 0;
}