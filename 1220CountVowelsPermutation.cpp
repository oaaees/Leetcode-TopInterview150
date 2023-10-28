#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(5, vector<int>(n, 0));
    	
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 5; j++){
                
            }
        }

        long long sum = 0;

        for (int i = 0; i < 5; i++){
            sum += dp[i][0];
        }

        return sum;
    }
};

int main (){
    Solution sol;
    cout << sol.countVowelPermutation(1);

    return 0;
}