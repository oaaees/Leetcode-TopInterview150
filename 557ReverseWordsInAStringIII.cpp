#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words = {};
        string temp = "";

        for(int i = 0; i < s.size(); i++){
            if( s[i] == ' ' || i = s.size() - 1){
                words.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }

        for(string word : words){
            int i = 0, j = word.size() - 1;
            while(i < j){
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
                i++;
                j--;
            }
            temp += word + " ";
        }

        return temp;
    }
};

int main (){
    Solution sol;

    cout << sol.reverseWords("Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.") << '\n';

    return 0;
}