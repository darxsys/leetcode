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
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty()) return false;

        int n = graph.size();
        vector<int> colors(n, -1);

        colors[0] = 0;
        queue<int> q;
        q.push(0);
        for (int i = 0; i < n; ++i)
        {
            if (colors[i] == -1) q.push(i);

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int j = 0; j < graph[cur].size(); ++j)
                {
                    int next = graph[cur][j];
                    if (colors[next] != -1 && colors[next] == colors[cur]) return false;
                    if (colors[next] == -1)
                    {
                        colors[next] = colors[cur] ^ 1;
                        q.push(next);
                    }
                }
            }
        }

        return true;      
    }
};


int main()
{
    Solution s;
    vector<vector<int>> graph({{1,3}, {0,2}, {1,3}, {0,2}});
    assert(s.isBipartite(graph) == true);

    graph = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    assert(s.isBipartite(graph) == false);

    graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    assert(s.isBipartite(graph) == false);

    graph = {{},{3},{},{1},{}};
    assert(s.isBipartite(graph) == true);

    return 0;
}