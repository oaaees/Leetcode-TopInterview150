#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 1));
        int mod = 1000000007;
    	
        for(int i = 1; i < n; i++){
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = (dp[i - 1][2]) % mod;
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }

        long long sum = 0;

        for (int i = 0; i < 5; i++){
            sum += dp[n - 1][i];
        }

        return sum % mod;
    }
};

int main (int argc, char *argv[]){
    Solution sol;
    cout << sol.countVowelPermutation(stoi(argv[1]));

    return 0;
}