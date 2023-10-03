#include <vector>
#include <iostream>
using namespace std;

// If range of num[i] is small a solution O(n) could be possible

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]) sum++;
            }
        }

        return sum;
    }
};

int main (){
    Solution sol;
    vector<int> nums = {1,1,1,1,1};

    cout << "Number of pairs is: " << sol.numIdenticalPairs(nums);

    return 0;
}