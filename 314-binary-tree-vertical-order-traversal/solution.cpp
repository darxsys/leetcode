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
        if (root == nullptr) return vector<vector<int>>();
        
        unordered_map<int, vector<pair<int, int>>> s;
        int m = 0;
        int M = 0;
        
        solve(root, s, m, M, 0, 0);
        vector<vector<int>> sol;
        for (int i = m; i <= M; ++i)
        {
            int n = s[i].size();
            vector<int> v(n);
            stable_sort(s[i].begin(), s[i].end(), Compare);
            for (int j = 0; j < n; ++j)
            {
                v[j] = s[i][j].second;
            }
            
            sol.emplace_back(v);
        }
        
        return sol;
    }
private:
    void solve(TreeNode *root, unordered_map<int, vector<pair<int, int>>> &s, int &m, int &M, int cur, int d)
    {
        if (root == nullptr) return;
        
        if (s.find(cur) == s.end())
            s[cur] = {{d, root->val}};
        else
            s[cur].push_back({d, root->val});
        
        m = min(m, cur);
        M = max(M, cur);
        
        solve(root->left, s, m, M, cur-1, d+1);
        solve(root->right, s, m, M, cur+1, d+1);
    }
    
    static bool Compare(const pair<int, int> &first, const pair<int, int> &second)
    {
        return first.first < second.first;
    }
};


int main()
{
    return 0;
}