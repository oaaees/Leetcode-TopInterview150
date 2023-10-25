#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)  return 0;
        if (k % 2) return kthGrammar(n-1, k/2 + 1);
        return !kthGrammar(n-1, k/2);
    }
};

int main (){
    Solution sol;
    cout << sol.kthGrammar(3, 1);
}