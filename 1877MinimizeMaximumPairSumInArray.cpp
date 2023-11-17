#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        	sort(nums.begin(), nums.end());
            int max = nums[0];

            for(int i = 0; i < nums.size() / 2; i++){
                if(nums[i] + nums[nums.size() - 1 - i] > max) max = nums[i] + nums[nums.size() - 1 - i];
            }

            return max;
    }
};

int main (){
    Solution sol;
    vector<int> nums = {4,1,5,1,2,5,1,5,5,4};
    cout << sol.minPairSum(nums) << "\n";

    for(int x : nums) cout << x << " "; 

    return 0;
}