#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int turns = 0;

        if (colors.size() < 3) return false;

        for(int i = 0; i < colors.size() - 2; i++){
            if(colors[i] == 'A' && colors[i + 1] == 'A' && colors[i + 2] == 'A') turns++;
            if(colors[i] == 'B' && colors[i + 1] == 'B' && colors[i + 2] == 'B') turns--;
        }

        if ( turns > 0 ) return true;
        return false;
    }
};

int main (){
    Solution sol;

    cout << "Can alice win? Anser: " << sol.winnerOfGame("AAAAAAAAAAAAAAAAAAAAAAAAAB");

    return 0;
}