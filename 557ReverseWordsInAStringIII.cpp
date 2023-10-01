#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words = {};
        string temp = "";

        for(int i = 0; i < s.size() + 1; i++){
            if( i == s.size() || s[i] == ' ' ){
                words.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }

        for(int k = 0; k < words.size(); k++){
            int i = 0, j = words[k].size() - 1;
            while(i < j){
                char temp = words[k][i];
                words[k][i] = words[k][j];
                words[k][j] = temp;
                i++;
                j--;
            }
            temp += words[k];
            if(k != words.size() - 1) temp += " ";
        }

        return temp;
    }
};


int main (){
    Solution sol;

    cout << sol.reverseWords("Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.") << '\n';

    return 0;
}