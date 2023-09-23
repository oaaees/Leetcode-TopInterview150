#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<vector<int>> letters(26, {0,0});
        string res = "";

        for(int i = 0; i < s.length(); i++){
            if(letters[s[i] - 97][1] == 0){
                letters[s[i] - 97][0] == s[i];
            }

            letters[s[i] - 97][1]++;
        }

        sort(letters.begin(), letters.end(), [](vector<int> a, vector<int> b){ return a[1] > b[1]; });

        for(int i = 0; i < letters.size(); i++){
            if(letters[i][1] == 0) {
                letters.erase(letters.begin()+i, letters.end());
                break;
            }
        }

        while(letters.size() > 0){
            if(letters[0][1] == 0) letters.erase(letters.begin());
            if(letters[1][1] == 0) letters.erase(letters.begin()+1);

            res += letters[0][0]--;
            res += letters[1][0]--;
        }

        return res;
    }
};

int main (){
    Solution sol;
    string s = "gloriaalbravopuebloqueelyugolanzolaleyrespetandolavirtudyhonor";
    cout << '\n' << sol.reorganizeString(s);
}