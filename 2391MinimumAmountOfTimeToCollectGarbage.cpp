#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum = 0;
        bool paper = false, metal = false, glass = false;

        for(int i = garbage.size() - 1; i >= 0; i--){
            if (!paper) paper = find('P', garbage[i]);
            if (!metal) metal = find('M', garbage[i]);
            if (!glass) glass = find('G', garbage[i]);

            sum += garbage[i].size();
            if(i != 0) sum += travel[i - 1] * (paper + metal + glass);
        }

        return sum;
    }
    bool find(char c, string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c) return true;
        }
        return false;
    }
};

int main (){
    Solution sol;
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2,4,3};
    cout << sol.garbageCollection(garbage, travel); 

    return 0;
}