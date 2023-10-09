#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right) {
            int m = left + (right - left) / 2;
    
            if (nums[m] == target){
                index = m;
                break;
            } else if (nums[m] < target){
                left = m + 1;
            } else {
                right = m - 1;
            }
        }

        if(index == -1) return {-1, -1};

        int begin = index, end = index;

        for(int i = end; i < nums.size(); i++){
            if(nums[end + 1] == target) end++;
        }
        for(int i = begin; i >= 0; i--){
            if(nums[begin - 1] == target) begin--;
        }

        return {begin, end};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1};
    int target = 1;

    vector<int> v = sol.searchRange(nums, target);

    for(int x : v){
        cout << x << " ";
    }
}