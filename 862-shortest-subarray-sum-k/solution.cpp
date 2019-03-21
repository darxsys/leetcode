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
    int shortestSubarray(vector<int>& A, int K) {
        if (A.empty()) return -1;
        
        int n = A.size();
        deque<int> q;
        int sol = n + 1;
        vector<int> sum(n+1, 0);
        
        for (int i = 0; i < n; ++i)
        {
            sum[i+1] = A[i] + sum[i];
        }
        
        q.push_back(0);
        
        for (int i = 1; i <= n; ++i)
        {
            while (!q.empty() && sum[q.back()] >= sum[i]) q.pop_back();
            while (!q.empty() && sum[q.front()] + K <= sum[i])
            {
                sol = min(sol, i - q.front());
                q.pop_front();
            }
            
            q.push_back(i);
        }
        
        return sol < n + 1 ? sol : -1;
    }
};

int main()
{
    Solution s;
    vector<int> input({77, 19, 35, 10, -14});
    s.shortestSubarray(input, 19);
    return 0;
}