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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int m = INT_MIN;
        unordered_map<TreeNode*, int> vals;
        helper(root, vals, m);
        return m;
    }
private:
    pair<int, int> helper(TreeNode* cur, unordered_map<TreeNode*, int> &vals, int &m)
    {
        if (cur == nullptr) return {0, 0};

        pair<int, int>left = helper(cur->left, vals, m);
        pair<int, int> right = helper(cur->right, vals, m);

        // left + current + right
        int sum1 = left.first + right.first;
        int sum2 = left.first + right.second;
        int sum3 = left.second + right.first;
        int sum4 = left.second + right.second;

        int v = max(sum1, sum2);
        v = max(v, sum3);
        v = max(v, sum4);
        v = v + cur->val;
        v = max(v, cur->val);
        m = max(m, v);

        // left + current
        int l = max(left.first, left.second) + cur->val;
        m = max(m, l);
        // right + current
        int r = max(right.first, right.second) + cur->val;
        m = max(m, r);


        return {max(l, cur->val), max(r, cur->val)};
    }
};

int main()
{
    return 0;
}