#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num_buckets = 10;
        vector<vector<vector<int>>> hashmap (num_buckets, vector<vector<int>>(0, vector<int>(2, 0)));

        for (int i = 0; i < nums.size(); i++){
            int bucket = nums[i] % num_buckets;
            bool found = false;

            if(bucket < 0) bucket *= -1;

            for(int j = 0; j < hashmap[bucket].size(); j++){
                if(nums[i] == hashmap[bucket][j][0]){
                    hashmap[bucket][j][1]++;
                    found = true;
                    break;
                } 
            }
            
            if(!found){
                hashmap[bucket].push_back({nums[i], 1});
            }
        }

        vector<int> result = {};
    
        for(int i = 0; i < hashmap.size(); i++){
            for(int j = 0; j < hashmap[i].size(); j++){
                if(hashmap[i][j][1] > (nums.size() / 3)) result.push_back(hashmap[i][j][0]);
            }
        }

        return result;
    }
};

int main (){
    Solution sol;
    vector<int> nums = {4,5,3,4,4,1,0,-1,-2,4,6,7,8,4};

    vector<int> v = sol.majorityElement(nums);

    for(int x : v){
        cout << x << " ";
    }

    return 0;
}