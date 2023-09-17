#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //TRANSPOSE

        int n = matrix[0].size();     
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++ ){
                int temp = matrix[i][j];
                matrix[i][j] = matrix [j][i];
                matrix[j][i] = temp;
            }
        }

        //REVERSE

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }

    }
};

int main (){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    sol.rotate(matrix);

    for( vector<int> v : matrix){
        for( int x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}