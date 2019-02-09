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
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();

        deque<TreeNode* > q;
        vector<vector<int> > ret;

        q.push_back(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i)
            {
                TreeNode* cur = q.front();
                q.pop_front();
                level[i] = cur->val;
                if (cur->left != nullptr) q.push_back(cur->left);
                if (cur->right != nullptr) q.push_back(cur->right);
            }

            ret.push_back(level);
        }

        return ret;
    }
};

int main()
{
    return 0;
}