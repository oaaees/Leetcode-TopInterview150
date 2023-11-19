#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        for(int i = nums.size() - 1; i >= 1; i--){
            if(nums[i-1] != nums[i]) s += (nums.size() - i);
        }
        return s;
    }
};

int main (){
    Solution sol;
    vector<int> nums = {1,1,2,2,3};
    cout << sol.reductionOperations(nums);
    return 0;
}