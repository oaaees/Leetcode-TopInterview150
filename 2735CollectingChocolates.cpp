#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        long long x_times = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        while(x_times < n) {
            long long sum_temp = 0;
            int first = nums[0];

            for(int i = 0; i < n - 1; i++){
                if(nums[i+1] < nums[i]){
                    nums[i] = nums[i+1];
                }
                sum_temp += nums[i];
            }

            if(first < nums[n - 1]) nums[n - 1] = first;
            sum_temp += nums[n-1];

            x_times++;
            sum_temp += (x_times * x);

            if(sum_temp < sum) sum = sum_temp;
        }

        return sum;
    }
};

int main () {
    Solution sol;
    vector<int> nums = {20,1,15};
    int x = 5;

    cout << "Min cost is: " << sol.minCost(nums, x);

    return 0;
}