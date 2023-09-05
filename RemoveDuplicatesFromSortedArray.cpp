#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int index = 0;

        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[index]){
                nums[++index] = nums[i];
            }
        }

        return index+1;
    }
};

int main (){
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    cout << "with " << sol.removeDuplicates(nums) << " unique numbers\n";

    for(int x : nums){
        cout << x << " ";
    }

    return 0;
}