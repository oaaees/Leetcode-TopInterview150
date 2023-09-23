#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<vector<int>> letters(26, {0,0,0});
        string res = "";

        for(int i = 0; i < s.length(); i++){
            if(letters[s[i] - 97][1] == 0){
                letters[s[i] - 97][0] = s[i];
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
            if(letters.size() == 1 && letters[0][2] == 1 && letters[0][1] != 0){
                return "";
            }

            if(letters[0][1] == 0){
                letters.erase(letters.begin());
                continue;
            } else if (letters.size() >= 2 && letters[1][1] == 0){
                letters.erase(letters.begin()+1);
                continue;
            }

            if(letters[0][2] == 0){
                res += letters[0][0];
                letters[0][1]--;
                letters[0][2] = 1;
                if (letters.size() > 1) letters[1][2] = 0;
            } else {
                res += letters[1][0];
                letters[1][1]--;
                letters[1][2] = 1;
                letters[0][2] = 0;
            }
        }

        // This hardcoded version will not work if more than two letters are tied 

        // Possible solution: 
            //1 make a variable called last (could be just an int with the index of letters)
            //2 in while loop find the letter with most appereances, 
                	//add it in res, 
                    //substract one, 
                    //make it unusable, 
                    //make last usable
            //3 update last
            //4 if the variable we just used has 0 appereances left, erase it from letters, go back to beginning of loop
        
        //Have to figure out a way such that erasing a variable does not fuck up "last"

        return res;
    }
};

int main (){
    Solution sol;
    string s = "aabbcc";
    cout << '\n' << sol.reorganizeString(s);
}