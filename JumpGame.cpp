#include <vector>
#include <iostream>
using namespace std;

// NOTE
// This is not the fastest solution, fastest is to traverse the array backwards from nums[nums.size() - 1] and checking if it gets to nums[0]
// My solution seems to work, just slower.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        if (nums.size() <= 1) return true;

        while(i < nums.size()) {
            if(nums[0] == 0){
                return false;
            }

            if(nums[i] == 0){
                i--;
            } else {
                int jump = nums[i];

                if(i + jump >= nums.size() - 1){
                    return true;
                } else {
                    if(nums[i + jump] == 0){
                        nums[i]--;
                    } else {
                        i += nums[i];
                    }
                }
            }
        }

        return true;
    }
};

int main (){
    Solution sol;
    vector<int> nums{2,3,1,1,4};
    cout << "answer is: " << sol.canJump(nums);

    return 0;
}