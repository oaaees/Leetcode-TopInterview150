#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        int sel_sum = 0;
        vector<int> result = {};

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        while( sel_sum <= sum ){
            int max = 0;

            for(int i = 1; i < nums.size(); i++){
                if( nums[i] > nums[max] ){
                    max = i;
                }
            }

            sum -= nums[max];
            sel_sum += nums[max];
            result.push_back(nums[max]);
            nums.erase(nums.begin() + max);
        }

        return result;
    }
};

int main (){

    Solution sol;
    vector<int> nums = {4,3,10,9,8};

    vector<int> result = sol.minSubsequence(nums);

    for(int x : result){
        cout << x << " ";
    }    

    return 0;
}