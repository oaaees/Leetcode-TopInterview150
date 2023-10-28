#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 1));
    	
        for(int i = 1; i < n; i++){
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % 1000000007;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000007;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % 1000000007;
            dp[i][3] = (dp[i - 1][2]) % 1000000007;
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000007;
        }

        long long sum = 0;

        for (int i = 0; i < 5; i++){
            sum += dp[n - 1][i];
        }

        return sum;
    }
};

int main (int argc, char *argv[]){
    Solution sol;
    cout << sol.countVowelPermutation(stoi(argv[1]));

    return 0;
}