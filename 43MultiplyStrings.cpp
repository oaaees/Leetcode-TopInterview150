#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string n1, string n2) {
        if(n1 == "0" || n2 == "0") return "0";
        vector<vector<int>> to_sum(n2.size(), vector<int>(n2.size() + n1.size(), 0));

        for(int i = n2.size() - 1; i >= 0; i--){
            for(int j = n1.size() - 1; j >= 0; j--){
                int a = n2[i] - 48, b = n1[j] - 48;

                to_sum[n2.size() - i - 1][j + i + 1] = a * b;
            }
        }

        string res = "";

        for(int i = to_sum[0].size() - 1; i >= 0; i--){
            int sum = 0;

            for(int j = 0; j < to_sum.size(); j++){
                sum += to_sum[j][i]; 
            }

            if(sum >= 10){ 
                to_sum[0][i - 1] += (sum / 10);
                sum = sum % 10;
            }

            res.insert(res.begin(), sum + 48);
        }

        int not_zero = -1;

        for(int i = 0; i < res.size(); i++){
            if(res[i] != '0'){
                not_zero = i;
                break;
            }
        }

        return res.substr(not_zero, res.size() - not_zero);
    }
};

int main (){
    Solution sol;
    cout << sol.multiply("0", "123456789");
    return 0;
}