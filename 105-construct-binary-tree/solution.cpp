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

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }

        return construct(preorder, cur, 0, n-1);
    }
private:
    TreeNode* construct(vector<int>& preorder, int& cur, int left, int right)
    {
        if (left > right) return nullptr;

        int val = preorder[cur];
        int i = index[val];
        TreeNode* t = new TreeNode(preorder[cur++]);
        t->left = construct(preorder, cur, left, i-1);
        t->right = construct(preorder, cur, i+1, right);

        return t;
    }

    unordered_map<int, int> index;
    int cur = 0;
};


int main()
{
    Solution s;
    vector<int> preorder({3, 9, 20, 15, 7});
    vector<int> inorder({9, 3, 15, 20, 7});
    s.buildTree(preorder, inorder);
    return 0;
}