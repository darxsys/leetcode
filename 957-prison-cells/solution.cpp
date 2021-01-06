class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0) return cells;
        
        auto [i, cycle] = runGame(cells, N);
        
        if (i == N) return cells;
        
        int mod = (N - i) % cycle;
        
        // now just need to repeat mod times to get the result
        runGame(cells, mod);
        
        return cells;
    }
private:
    pair<int, int> runGame(vector<int>& cells, int times) {
        unordered_map<int, int> store;
        int bitmask = (1 << cells.size()) - 1;
        
        for (int i = 0; i < cells.size(); ++i) {
            if (cells[i] == 0)
            bitmask = bitmask & (~(1 << i));
        }
        
        store.emplace(bitmask, 0);
        
        int i = 1;
        for (; i <= times; ++i) {
            int prev = cells[0];
            bitmask = 0;
            for (int j = 1; j < cells.size()-1; ++j) {
                if (prev == cells[j+1]) {
                    prev = cells[j];
                    cells[j] = 1;
                } else {
                    prev = cells[j];
                    cells[j] = 0;
                }
                
                if (cells[j] == 1) {
                    bitmask = bitmask | (1 << j);
                }
            }
            
            if (store.find(bitmask) != store.end()) {
                break;
            }
            
            store.emplace(bitmask, i);
            cells[0] = cells.back() = 0;
        }
        
        return pair<int, int>(i, i - store.at(bitmask));
    }
};