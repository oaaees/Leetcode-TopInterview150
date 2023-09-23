#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> letters(27, 0);
        letters[26] = -1; 
        string res = "";

        for(int i = 0; i < s.length(); i++){
            letters[s[i] - 97]++;
        }

        int last = 26;

        while(res.size() < s.size()){
            int max = 26;

            for(int i = 0; i < letters.size() - 1; i++){
                if(letters[i] > letters[max] && i != last) max = i;     
            }

            if(letters[max] == 0) return "";

            res += (max + 97);
            letters[max]--;
            last = max;
        }

        return res;
    }
};

int main (){
    Solution sol;
    string s = "gloriaalbravopuebloqueelyugolanzolaleyrespetandolavirtudyhonorabajocadenasabajocadenasgritabaelsenor";
    cout << '\n' << sol.reorganizeString(s);
}