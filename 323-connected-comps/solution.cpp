class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> uf(n);
        for (int i = 0; i < n; ++i) {
            uf[i] = i;
        }
        
        for (auto& edge : edges) {
            connect(uf, edge);
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (uf[i] == i) count++;
        }
        
        return count;
    }
private:
    int find(vector<int>& uf, int i) {
        while (uf[i] != i) {
            uf[i] = uf[uf[i]];
            i = uf[i];
        }
        return i;
    }
    
    void connect(vector<int>& uf, vector<int>& edge) {
        int parenta = find(uf, edge[0]);
        int parentb = find(uf, edge[1]);
        
        if (parenta != parentb) {
            uf[parentb] = parenta;
        }
    }
};