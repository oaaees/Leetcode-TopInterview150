#include <string>
#include <vector>
#include <iostream>
using namespace std;

// This is not near the fastest solution, but I'm not in the mental state to understand the winners on leetcode

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> nums(s.size());

        for(int i = 0; i < s.size(); i++){
            nums[i] = s[i] - 96;
            for(int j = 0; j < chars.size(); j++){
                if(s[i] == chars[j]){
                    nums[i] = vals[j];
                    break;
                }
            }
        }

        int max = nums[0], temp_max = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] + temp_max > nums[i]){
                temp_max += nums[i];
            } else {
                temp_max = nums[i];
            }

            if(temp_max > max) max = temp_max;
        }

        return max;

    }
};

int main(){
    Solution sol;
    string s = "adaa";
    string chars = "d";
    vector<int> vals = {-1000};

    cout << "maximum cost is: " << sol.maximumCostSubstring(s, chars, vals);

    return 0;
}