#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m, 0);
        vector<int> result = {};

        for(int i = m - 1; i >= 0; i--){
            p[i] = m - i;
        }

        for(int i = 0; i < queries.size(); i++){
            for(int j = 0; j < p.size(); j++){
                if(queries[i] == p[j]){
                    int temp = p[j];
                    p.erase(p.begin() + j);
                    p.push_back(temp);
                    result.push_back(m - j - 1);
                    break;
                }
            }
        }

        return result;
    }
};

int main (){
    Solution sol;
    vector<int> queries = {7,5,5,8,3};
    int m = 8;

    vector<int> v = sol.processQueries(queries, m);

    for(int x : v){
        cout << x << " ";
    }

    return 0;
}