class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> q;
        vector<int> result;
        int n = asteroids.size();
        vector<int> keep(n, true);
        
        int i = 0;
        while (i < n && asteroids[i] < 0) ++i;
        
        for (; i < n; ++i) {
            if (asteroids[i] > 0) {
                q.push_back(i);
            } else {
                int val = -asteroids[i];
                
                while (!q.empty() && asteroids[q.back()] < val) {
                    keep[q.back()] = false;
                    q.pop_back();
                }
                
                if (!q.empty() && asteroids[q.back()] >= val) {
                    keep[i] = false;
                    if (asteroids[q.back()] == val) {
                        keep[q.back()] = false;
                        q.pop_back();
                    }
                }
            }
        }
        
        result.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (keep[i]) {
                result.emplace_back(asteroids[i]);
            }
        }
        
        return result;
    }
};