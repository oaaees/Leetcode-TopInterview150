#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int low = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < low){
                low = prices[i];
            } else {
                if(prices[i] - low > max){
                    max = prices[i] - low;
                }
            }
        }
        
        return max;
    }
};

int main (){
    vector<int> prices{7,1,5,3,6,4};
    Solution sol;
    cout << "max profit is " << sol.maxProfit(prices);

    return 0;
}