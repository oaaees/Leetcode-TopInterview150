#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;
        int n_0 = 1, m_0 = 0;
        vector<int> spiral = {};
        int i = 0, j = 0; 
        
        enum dir {
            right, 
            down,
            left,
            up
        };

        dir current = (m > 1) ? right : down;

        while (spiral.size() < total){
            switch(current){
                case right:
                    spiral.push_back(matrix[i][j]);
                    j++;
                    if(j == m - 1){ 
                        current = down;
                        m--;
                    }
                    break;
                case down:
                    spiral.push_back(matrix[i][j]);
                    i++;
                    if(i == n - 1){ 
                        current = left;
                        n--;
                    }
                    break;
                case left:
                    spiral.push_back(matrix[i][j]);
                    j--;
                    if(j == m_0){
                        current = up;
                        m_0++;
                    }
                    break;
                case up:
                    spiral.push_back(matrix[i][j]);
                    i--;
                    if(i == n_0){ 
                        current = right;
                        n_0++;
                    }
                    break;
            }
        }

        return spiral;
    }
};

int main (){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    // 1 2 3
    // 4 5 6
    // 7 8 9 

    Solution sol;
    vector<int> spiral = sol.spiralOrder(matrix);

    cout << "Spiral order: ";

    for( int x : spiral){
        cout << x << " ";
    }

    return 0;
}