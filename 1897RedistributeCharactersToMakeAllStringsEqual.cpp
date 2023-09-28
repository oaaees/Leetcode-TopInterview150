#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> num_chars(26, 0);

        for(string word : words){
            for(int i = 0; i < word.size(); i++){
                num_chars[word[i] - 'a']++;
            }
        }

        for(int i = 0; i < num_chars.size(); i++){
            if(num_chars[i] % words.size() != 0) return false; 
        }

        return true;
    }
};

int main () {
    Solution sol;
    vector<string> words = {"aaa", "bbb", "ccc"};

    if(sol.makeEqual(words)){
        cout << "They can be equal";
    } else {
        cout << "They can not be equal";
    }

    return 0;
}