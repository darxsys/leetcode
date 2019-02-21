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

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if (root == nullptr) return sol;
        
        unordered_map<int, vector<int>> m;
        deque<pair<int, TreeNode*>> q;
        q.push_back({0, root});
        int left = 0;
        int right = 0;
        while(!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                int d = q.front().first;
                TreeNode *cur = q.front().second;
                q.pop_front();
                
                m[d].push_back(cur->val);
                
                if (cur->left != nullptr)
                {
                    q.push_back({d-1, cur->left});
                    left = min(left, d-1);
                }
                if (cur->right != nullptr)
                {
                    q.push_back({d+1, cur->right});
                    right = max(right, d+1);
                }
            }
        }
        
        for (int i = left; i <= right; ++i)
        {
            sol.emplace_back(m[i]);
        }

        return sol;
    }
};

int main()
{
    return 0;
}