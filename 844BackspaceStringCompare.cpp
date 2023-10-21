#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res_s = "";
        string res_t = "";

        for(int i = 0; i < s.size(); i++){
            if (s[i] == '#'){
                if (res_s.size() > 0) res_s.pop_back();
            } else {
                res_s.push_back(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++){
            if (t[i] == '#'){
                if (res_t.size() > 0) res_t.pop_back();
            } else {
                res_t.push_back(t[i]);
            }
        }

        return res_s == res_t;
    }
};

int main(){

    Solution sol;

    cout << sol.backspaceCompare("ab#c", "ad#c");

    return 0;
}