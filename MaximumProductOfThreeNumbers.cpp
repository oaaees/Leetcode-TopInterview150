#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        for(int j = 0; j < 3; j++){
            for(int i = 0; i < n - j - 1; i++){
                if(nums[i] > nums[i + 1]){
                    int temp = nums[i + 1];
                    nums[i + 1] = nums[i];
                    nums[i] = temp;
                }
            }
        }

        for(int j = 0; j < 2; j++){
            for(int i = n - 3; i > 0; i--){
                if(nums[i] < nums[i - 1]){
                    int temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;
                }
            }
        }

        for(int x : nums){
            cout << x << " ";
        }

        cout << '\n';

        int op1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int op2 = nums[0] * nums[1] * nums[n - 1];

        if( op1 > op2) {
            return op1;
        } else {
            return op2;
        }
    }
};

int main (){
    vector<int> nums = {3,4,0,0,-1,-5};
    Solution sol;

    cout << "Max is " << sol.maximumProduct(nums);

    return 0;
}