#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 1) return {-1};

        int max_index = 0;
        int i = 0;

        while (i != arr.size() - 1){
            if (max_index <= i){
                max_index = i + 1;
                for(int j = i + 2; j < arr.size(); j++){
                    if(arr[j] >= arr[max_index]) max_index = j;
                }
            }

            arr[i] = arr[max_index];
            i++;
        }

        arr[arr.size() - 1] = -1;
        return arr;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {56903,18666,60499,57517,26961};
    sol.replaceElements(nums);

    for(int x : nums) cout << x << " ";

    return 0;
}