#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int b = 0, f = s.size() - 1;

        while(f > b){
            if(isalpha(s[b]) && isalpha(s[f])){
                char temp = s[b];
                s[b] = s[f];
                s[f] = temp;
                b++;
                f--;
                continue;
            }

            if(!isalpha(s[b])) b++;
            if(!isalpha(s[f])) f--;
        }

        return s;
    }
};

int main(){
    Solution sol;

    cout << sol.reverseOnlyLetters("ab-cd");

    return 0;
}