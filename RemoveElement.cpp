#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main(){
    vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;

    Solution a;
    cout << "k = " << a.removeElement(nums, val) << "\nnums = "; 

    for(int x : nums){
        cout << x << " ";
    }

    return 0;
}