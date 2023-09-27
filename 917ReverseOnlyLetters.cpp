#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string temp = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') temp += s[i]; 
        }

        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') s[i] = temp[count++]; 
        }

        return s;
    }
};

int main(){
    Solution sol;

    cout << sol.reverseOnlyLetters("ab-cd");

    return 0;
}