#include <vector>
#include <iostream>
using namespace std;

// Not a quick solution at all, recursion could be used but it didn't called Too Long to Execute so ¯\_(ツ)_/¯

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
    int averageOfSubtree(TreeNode* root) {
        vector<TreeNode *> current_level = {root};
        int count = 0;
        
        while(current_level.size() != 0){
            vector<TreeNode *> next_level = {};

            for(int i = 0; i < current_level.size(); i++){
                if(avg(current_level[i]) == current_level[i]->val) count++;
                if(current_level[i]->left != nullptr) next_level.push_back(current_level[i]->left);
                if(current_level[i]->right != nullptr) next_level.push_back(current_level[i]->right);   
            }

            current_level = next_level;
        }

        return count;
    }
    int avg(TreeNode * root){
        vector<TreeNode *> current_level = {root};
        int sum = 0, n = 0;

        while(current_level.size() != 0){
            vector<TreeNode *> next_level = {};

            for(int i = 0; i < current_level.size(); i++){
                sum += current_level[i]->val;
                n++;

                if(current_level[i]->left != nullptr) next_level.push_back(current_level[i]->left);
                if(current_level[i]->right != nullptr) next_level.push_back(current_level[i]->right);
            }

            current_level = next_level;
        }

        return (sum / n);
    }
};

int main(){
    Solution sol;

    TreeNode t1(0);
    TreeNode t2(1);
    TreeNode t3(6);

    TreeNode t4(8, &t1, &t2);
    TreeNode t5(5, nullptr, &t3);

    TreeNode t6(4, &t4, &t5);

    cout << sol.averageOfSubtree(&t6);

    return 0;
}