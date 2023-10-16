#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current_row = {1};

        for(int i = 1; i <= rowIndex; i++){
            vector<int> next_row(current_row.size() + 1, 0);

            for(int j = 0; j < current_row.size(); j++){
                next_row[j] += current_row[j];
                next_row[j + 1] += current_row[j];
            }

            current_row = next_row;
        }

        return current_row;
    }
};

int main(){
    Solution sol;
    vector<int> row = sol.getRow(30);

    for(int x : row){
        cout << x << " ";
    }
}