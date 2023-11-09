#include <iostream>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1) return false;
        return (max(abs(fx - sx), abs(fy - sy)) <= t);
    }
    int max(int a, int b){
        if( a > b ) return a;
        return b;
    }
    int abs(int a){
        if (a < 0) return -a;
        return a;
    }
};

int main (){
    Solution sol;
    cout << sol.isReachableAtTime(1,1,2,3,4);

    return 0;
}