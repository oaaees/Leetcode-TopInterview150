#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<int> letters = {a, b, c, -1};
        string res = "";

        int last_last = 3;
        int last = 3;

        while(res.size() < a + b + c){
            int max = 3;

            for(int i = 0; i < letters.size() - 1; i++){
                if(letters[i] > letters[max] && !(i == last && i == last_last)) max = i;     
            }

            if(letters[max] == 0) return res;

            res += (max + 97);
            letters[max]--;
            last_last = last;
            last = max;
        }

        return res;
    }
};

int main (){
    Solution sol;
    cout << "Hey\n" << sol.longestDiverseString(1,1,7);
}