#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<long> count(arr.size(), 1);

        for(int i = 1; i < arr.size(); i++){
            for(int j = i; j >= 0; j--){
                if(arr[i] % arr[j] == 0){
                    for(int k = i; k >= 0; k--){
                        if(arr[k] == arr[i] / arr[j]) count[i] += count[j] * count[k];
                    }
                }
            }
        }

        return sum(count) % 1000000007;
    }
    long sum(vector<long> & arr){
        long sum = 0;
        for(long x : arr) sum += x;
        return sum;
    }
};

int main (){
    Solution sol;
    vector<int> arr = {2,4,5,10};
    cout << sol.numFactoredBinaryTrees(arr);
    return 0;
}