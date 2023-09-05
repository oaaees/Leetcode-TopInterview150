#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj = nums[0];

        for(int x : nums){
            if (count == 0){
                maj = x;
                count++;
            } else {
                if(x == maj){
                    count++;
                } else {
                    count--;
                }
            }
        }

        return maj;
    }
};

int main (){
    vector<int> nums{2,2,1,1,1,2,2};
    Solution sol;
    cout << "majority element is " << sol.majorityElement(nums);

    return 0;
}