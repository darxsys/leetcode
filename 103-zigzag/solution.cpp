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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        deque<TreeNode*> left;
        deque<TreeNode*> right;
        
        left.push_back(root);
        while(!left.empty() || !right.empty()) {
            if (!left.empty()) {
                result.emplace_back(traverse(left, right, true));
            } else if (!right.empty()) {
                result.emplace_back(traverse(left, right, false));
            }
        }
        
        // recurse(root, result, true);
        return result;
    }
private:
    vector<int> traverse(deque<TreeNode*>& left, deque<TreeNode*>& right, bool isLeft) {
        vector<int> result;
        if (isLeft) {
            while (!left.empty()) {
                auto node = left.front();
                left.pop_front();
                result.emplace_back(node->val);

                if (node->left)
                    right.push_front(node->left);  
                if (node->right)
                    right.push_front(node->right);
            }
        } else {
            while (!right.empty()) {
                auto node = right.front();
                right.pop_front();

                result.emplace_back(node->val);
                if (node->right)
                    left.push_front(node->right);

                if (node->left)
                    left.push_front(node->left);
            }
        }
        
        return result;
    }
};