#include <cstdio>
#include <cstring>
#include <climits>
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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;

        recurse(root, "", ret);
        return ret;        
    }

private:
    void recurse(TreeNode* root, string cur, vector<string>& ret)
    {
        cur += cur != "" ? "->" + to_string(root->val) : to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) // leaf
        {
            ret.push_back(cur);
            return;
        }

        if (root->left) recurse(root->left, cur, ret);
        if (root->right) recurse(root->right, cur, ret);
    }
};


int main()
{
    return 0;
}