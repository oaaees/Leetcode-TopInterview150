#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> letters(26, 0);
        vector<int> reference = {};
        string res = "";

        for(int i = 0; i < s.length(); i++){
            if(letters[s[i] - 97] == 0) reference.push_back(s[i] - 97);
            letters[s[i] - 97]++;
        }

        while(reference.size() > 0){
            for(int i = 0; i < reference.size(); i++){
                res += reference[i] + 97;
                letters[reference[i]]--;

                if(letters[reference[i]] == 0) reference.erase(reference.begin()+i);
            }

            cout << res << '\n';
        }

        return res;
    }
};

int main (){
    Solution sol;
    string s = "gloriaalbravopuebloqueelyugolanzolaleyrespetandolavirtudyhonor";
    cout << '\n' << sol.reorganizeString(s);
}