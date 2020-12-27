class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        
        int n = M.size();
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(M, visited, i);
                count++;
            }
        }
        
        return count;
    }
private:
     void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
         visited[i] = true;
         for (int j = 0; j < M.size(); ++j) {
             if (M[i][j] && !visited[j]) {
                 dfs(M, visited, j);
             }
         }
     }
};