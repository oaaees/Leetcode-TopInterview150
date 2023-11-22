#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int, int, int>> nums2 = {};

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                nums2.push_back(make_tuple(i+j, j, nums[i][j]));
            }
        }

        sort(nums2.begin(), nums2.end(), [](auto a, auto b){
            if(get<0>(a) == get<0>(b)){
                return get<1>(a) < get<1>(b);
            } else {
                return get<0>(a) < get<0>(b);
            }
        });

        vector<int> res = {};

        for(int i = 0; i < nums2.size(); i++) res.push_back(get<2>(nums2[i]));
        return res;
    }
};

int main (){
    Solution sol;
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> d = sol.findDiagonalOrder(nums);

    cout << "diagonal order is: ";

    for(int x : d){
        cout << x << " ";
    }

    return 0;
}