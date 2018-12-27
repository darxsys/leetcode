class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0)
        {
            return vector<pair<int, int> >();
        }
        
        vector<pair<int, int> > solution;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > all;
        
        for (int i = 0; i < buildings.size(); ++i)
        {
            all.push(make_pair(buildings[i][0], buildings[i][2]));
            all.push(make_pair(buildings[i][1], -buildings[i][2]));
        }

        multiset<int, std::greater<int>> active;
        active.insert(0);
        
        while (!all.empty())
        {
            int x = all.top().first;
            while (!all.empty() && all.top().first == x)
            {
                int height = all.top().second;
                if (height > 0)
                {
                    active.insert(height);
                }
                else
                {
                    active.erase(active.find(-height));
                }
                
                all.pop();
            }

            
            int height = *active.begin();
            
            if (solution.size() == 0 || solution[solution.size()-1].second != height)
            {
                solution.emplace_back(make_pair(x, height));
            }
        }

        return solution;
                             
    }
private:
    struct Compare {
        bool operator()(const pair<int, int> &first, const pair<int, int> &second)
        {
            return first.first > second.first;
        };
    };
    
};