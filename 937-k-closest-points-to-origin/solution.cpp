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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.empty()) return vector<vector<int>>();
        
        vector<pair<int, int>> dist(points.size());
        for (int i = 0; i < points.size(); ++i)
        {
            dist[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        }
        
        sort(dist.begin(), dist.end(), compare);
        
        vector<vector<int>> sol(K);
        for (int i = 0; i < K; ++i)
        {
            sol[i] = points[dist[i].second];
        }
        
        return sol;
    }
    
private:
    static bool compare(const pair<int,int>& first, const pair<int, int>& second)
    {
        return first.first < second.first;
    }
};

int main()
{
    return 0;
}