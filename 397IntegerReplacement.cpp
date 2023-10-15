#include <iostream>
using namespace std;

class Solution {
public:
    long integerReplacement(long n) {
        long count = 0;

        while( n > 1 ){
            if(n == 3){ return count += 2; }

            if (n % 2){
                if( ((n + 1) & n) == 0 || (n + 1) % 4 == 0 ) {
                    n += 1;
                } else {
                    n -= 1;
                }
            } else {
                n /= 2;
            }
            count++;
        }
        
        return count;
    }
};

int main(){
    Solution sol;

    cout << sol.integerReplacement(10000);

    return 0;
}