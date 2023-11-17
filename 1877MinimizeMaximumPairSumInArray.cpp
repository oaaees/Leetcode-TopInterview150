#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        	sort(nums.begin(), nums.end());
            return nums[0] + nums[nums.size() - 1];
    }
};

int main (){
    Solution sol;
    vector<int> nums = {4,1,5,1,2,5,1,5,5,4};
    cout << sol.minPairSum(nums); 
    return 0;
}