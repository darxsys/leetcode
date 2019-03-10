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
    bool isValidBST(TreeNode* root) {
        bool res = true;
        recurse(root, &res);
        return res;
    }
private:
    pair<TreeNode*, TreeNode*> recurse(TreeNode* cur, bool* res)
    {
        if (cur == nullptr)
        {
            return {nullptr, nullptr};
        }
        
        pair<TreeNode*, TreeNode*> l = recurse(cur->left, res);
        pair<TreeNode*, TreeNode*> r = recurse(cur->right, res);
        
        if (l.second && l.second->val >= cur->val) *res = false;
        if (r.first && r.first->val <= cur->val) *res = false;
        
        TreeNode* m = l.first ? l.first : cur;
        TreeNode* M = r.second ? r.second : cur;
        
        return {m, M};
    }
};

int main()
{
    return 0;
}