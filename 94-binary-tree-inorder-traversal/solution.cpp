#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            while(root && root->left)
            {
                s.push(root->left);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            if (root->right)
            {
                s.push(root->right);
                root = root->right;
            }
            else
            {
                root = nullptr;    
            }
        }
        
        return ret;
    }
};

int main()
{
    return 0;
}