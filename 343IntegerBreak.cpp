#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    unsigned long long integerBreak(int n) {
        if (n <= 3){ return n - 1; }

        unsigned long long prod = 1;

        while(n > 4){
            prod *= 3;
            n -= 3;
        }

        prod *= n;

        return prod;
    }
};

int main (){
    Solution sol;

    cout << sol.integerBreak(54);
}