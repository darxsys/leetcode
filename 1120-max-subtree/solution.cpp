/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        recurse(root);
        return result; 
    }
private:
    pair<int, int> recurse(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        
        auto left = recurse(root->left);
        auto right = recurse(root->right);
        
        if (left.first)
            result = max(result, (double) left.second / left.first);
        
        if (right.first)
            result = max(result, (double) right.second / right.first);
        
        pair<int, int> ret(left.first + 1 + right.first, 
                              left.second + right.second + root->val);
        
        result = max(result, (double) ret.second / ret.first);
        
        return ret;
    }

    double result = 0;
};