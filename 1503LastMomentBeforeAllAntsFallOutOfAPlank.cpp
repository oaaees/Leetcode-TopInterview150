#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_left = 0, min_right = n;

        for(int i = 0; i < left.size(); i++){
            if(left[i] > max_left) max_left = left[i];
        }

       for(int i = 0; i < right.size(); i++){
            if(right[i] < min_right) min_right = right[i];
        }

        return max(max_left, n - min_right);
    }
    int max(int a, int b){
        if (a > b) return a;
        return b;
    }
};

int main (){
    Solution sol;
    vector<int> left = {4,3};
    vector<int> right = {0,1};

    cout << sol.getLastMoment(4, left, right);
    return 0;
}