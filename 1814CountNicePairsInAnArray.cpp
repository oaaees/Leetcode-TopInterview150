#include <vector>
#include <unordered_map>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++){
            int key = nums[i] - rev(nums[i]);
            auto search = hash.find(key);
            if(search != hash.end()){
                count += search->second;
                search->second++;
            } else {
                hash.insert({key, 1});
            }
        }

        return count % 1000000007;
    }

    int rev(int x){
        string s = to_string(x);
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            res += (s[i] - 48) * pow(10, (i));
        }
        return res;
    }
};

int main (){
    Solution sol;
    vector<int> nums = {13,10,35,24,76};
    cout << sol.countNicePairs(nums);
    return 0;
}