/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parents;
        
        parents[root] = nullptr;
        populateParents(root, parents);
        
        unordered_set<TreeNode*> visited;
        vector<int> result;
        
        dfs(target, visited, parents, result, K);
        return result;
    }
private:
    void populateParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root == nullptr) return;
        
        if (root->left) {
            parents[root->left] = root;
            populateParents(root->left, parents);
        }
        
        if (root->right) {
            parents[root->right] = root;
            populateParents(root->right, parents);
        }
    }
    
    void dfs(TreeNode* cur, unordered_set<TreeNode*>& visited, unordered_map<TreeNode*, TreeNode*>& parents, vector<int>& result, int K) {
        if (cur == nullptr || visited.find(cur) != visited.end()) return;
        
        visited.insert(cur);
        
        if (K == 0) {
            result.push_back(cur->val);
        } else {
            dfs(cur->left, visited, parents, result, K-1);
            dfs(cur->right, visited, parents, result, K-1);
            dfs(parents[cur], visited, parents, result, K-1);
        }
    }
};