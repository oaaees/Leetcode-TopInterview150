#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string n1, string n2) {
        if(n1 == "0" || n2 == "0") return "0";
        vector<int> to_sum(n2.size() + n1.size(), 0);

        for(int i = n2.size() - 1; i >= 0; i--){
            for(int j = n1.size() - 1; j >= 0; j--){
                int a = n2[i] - 48, b = n1[j] - 48;
                int c = a * b;

                to_sum[j + i] += c / 10;
                to_sum[j + i + 1] += c % 10;

                if(to_sum[j + i + 1] >= 10){
                    to_sum[j + i] += to_sum[j + i + 1] / 10;
                    to_sum[j + i + 1] %= 10;
                }
            }
        }

        string res = "";

        for(int i = 0; i < to_sum.size(); i++){
            if(res.size() == 0 && to_sum[i] == 0) continue;
            res.push_back(to_sum[i] + 48);
        }

        return res;
    }
};

int main (){
    Solution sol;
    cout << sol.multiply("123", "4567");
    return 0;
}