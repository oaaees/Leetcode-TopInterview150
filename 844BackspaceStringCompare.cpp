class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;




        return true;
    }
    int count_char(string s, char c){
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == c) count++;
        }

        return count;
    }
};