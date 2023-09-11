#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int latest = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > latest){
                sum += latest - prices[i];
                latest = prices[i];
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