#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> res(satisfaction.size() + 1, 0);

        for(int i = res.size() - 2; i >= 0; i--){
            for(int j = i; j < satisfaction.size(); j++){
                res[i] += satisfaction[j] * (j - i + 1);
            }
             
        }

        int max = res[0];

        for(int i = 0; i < res.size(); i++){
            if (res[i] > max) max = res[i];
        }

        return max;
    }
};

int main (){
    Solution sol;
    vector<int> satisfaction = {-1,-8,0,5,-9};
    cout << sol.maxSatisfaction(satisfaction);


    return 0;
}