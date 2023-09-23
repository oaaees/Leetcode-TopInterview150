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

        // This hardcoded version will not work if more than two letters are tied 

        // Possible solution: 
            //1 make a variable called last (could be just an int with the index in letters) (which is just the letter??)
            //2 in while loop find the letter with most appereances, 
                	//add it to res, 
                    //substract one, 
                    //make it unusable, 
                    //make last usable
            //3 update last
            //4 if the variable we just used has 0 appereances left, erase it from letters, go back to beginning of loop
        
        //Have to figure out a way such that erasing a variable does not fuck up "last", maybe just not erasing and instead check for all letters which are not 0

        return res;
    }
};

int main (){
    Solution sol;
    string s = "aaab";
    cout << '\n' << sol.reorganizeString(s);
}