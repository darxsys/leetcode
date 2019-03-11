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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int maks = 0;
        recurse(root, maks);
        return maks;
    }
private:
    int recurse(TreeNode* root, int& maks)
    {
        int left = root->left ? recurse(root->left, maks) + 1 : 0;
        int right = root->right ? recurse(root->right, maks) + 1 : 0;
        
        maks = max({maks, left, right, left + right});
        
        return max({left, right});   
    }
};


int main()
{
    return 0;
}