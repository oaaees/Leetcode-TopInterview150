#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1]){
                sum += prices[i] - prices[i - 1];
            }
        }
        
        return sum;
    }
};

int main (){
    vector<int> prices{7,1,5,3,6,4};
    Solution sol;
    cout << "max profit is " << sol.maxProfit(prices);

    return 0;
}