#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        for(int i = 0; i < nums[0].size(); i++){
            res += !(nums[i][i] - 48) + 48;
        }
        return res;
    }
};

int main (){
    Solution sol;
    vector<string> nums = {"10", "11"};
    cout << sol.findDifferentBinaryString(nums);
    return 0;
}