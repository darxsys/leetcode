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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr)
        {
            return vector<TreeNode*>({nullptr, nullptr});
        }

        vector<TreeNode*> ret;
        if (root->val <= V)
        {
            ret = splitBST(root->right, V);
            root->right = ret[0];
            ret[0] = root;
        }
        else
        {
            ret = splitBST(root->left, V);
            root->left = ret[1];
            ret[1] = root;
        }

        return ret;
    }
};


int main()
{
    return 0;
}