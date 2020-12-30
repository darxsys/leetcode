class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        
        for (const auto& edge : prerequisites) {
            in_degree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(numCourses, 0);
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
        
        vector<int> result;
        result.reserve(numCourses);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            
            for (int i = 0; i < adj[cur].size(); ++i) {
                int dest = adj[cur][i];
                in_degree[dest]--;
                if (in_degree[dest] == 0 && !visited[dest]) {
                    visited[dest] = 1;
                    q.push(dest);
                }
            }
        }
        
        return result.size() == numCourses ? result : vector<int>();
    }
};