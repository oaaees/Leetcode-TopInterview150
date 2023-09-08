#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        vector<int> p(nums.size(), 0); 

        for(int i = 0; i < nums.size(); i++){
            if(i >= nums.size() - k){
                p[i - nums.size() + k] = nums[i];
            } else {
                p[i+k] = nums[i];
            }
        }

        nums = p;
    }
};

int main (){
    vector<int> nums{-1};
    int k = 2;
    Solution sol;
    cout << "rotated array is ";

    sol.rotate(nums, k);

    for(int x : nums){
        cout << x << " ";
    }

    return 0;
}