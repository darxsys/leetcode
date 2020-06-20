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
// Naive solution
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        fillValues(root);
        
        int result = INT_MAX;
        for (int i = 0, j = 1; j < values_.size(); ++j, ++i) {
            result = min(result, values_[j] - values_[i]);
        }
        
        return result;
    }
    
private:
    void fillValues(TreeNode* root) {
        if (root == nullptr) return;
        fillValues(root->left);
        values_.push_back(root->val);
        fillValues(root->right);
    }
    vector<int> values_;
};

// no extra memory
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int result = INT_MAX;
        fillValues(root, result);
        return result;
    }
    
private:
    void fillValues(TreeNode* root, int& result) {
        if (root == nullptr) return;
        fillValues(root->left, result);
        if (value_.has_value()) {
            result = min(result, root->val - value_.value());
        }
        value_ = root->val;
        fillValues(root->right, result);
    }
    std::optional<int> value_;
};
