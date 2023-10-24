#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<TreeNode *> current_row = {root};
        vector<int> largest = {};

        while (current_row.size() > 0){
            int max = current_row[0]->val;
            for(TreeNode * x : current_row){
                if(x->val > max) max = x->val;
            }
            largest.push_back(max);

            vector<TreeNode *> next_row = {};
            for(int i = 0; i < current_row.size(); i++){
                if(current_row[i]->left) next_row.push_back(current_row[i]->left);
                if(current_row[i]->right) next_row.push_back(current_row[i]->right);
            }
            current_row = next_row;
        }

        return largest;
    }
};

int main (){
    TreeNode root(7);
    Solution sol;

    vector<int> largest = sol.largestValues(&root);

    for(int x : largest){
        cout << x << " ";
    }

    return 0;
}