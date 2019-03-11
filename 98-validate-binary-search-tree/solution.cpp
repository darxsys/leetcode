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

class Solution2 { // stack approach
public:
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        
        stack<TreeNode*> s;
        list<TreeNode*> low;
        list<TreeNode*> high;
        s.push(root);
        low.push_back(nullptr);
        high.push_back(nullptr);
        
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            TreeNode* l = low.back();
            low.pop_back();
            TreeNode* h = high.back();
            high.pop_back();
            
            if (l && cur->val <= l->val) return false;
            if (h && cur->val >= h->val) return false;
            
            if (cur->right)
            {
                s.push(cur->right);
                low.push_back(cur);
                high.push_back(h);
            }
            
            if (cur->left)
            {
                s.push(cur->left);
                low.push_back(l);
                high.push_back(cur);
            }
        }
        
        return true;
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        
        stack<TreeNode*> s;
        TreeNode* lastseen = nullptr;
        
        TreeNode* cur = root;
        while (cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        
        while(!s.empty())
        {
            cur = s.top();
            if (lastseen && lastseen->val >= cur->val) return false;
            lastseen = cur;
            s.pop();
            
            if (cur->right)
            {
                cur = cur->right;
                while(cur)
                {
                    s.push(cur);
                    cur = cur->left;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    return 0;
}