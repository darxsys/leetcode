class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        
        unordered_map<int, bool> dp;
       return recurse(maxChoosableInteger, desiredTotal, 0, dp);
    }
    
private:
    bool recurse(int maxInt, int total, int bitmask, unordered_map<int, bool>& dp) {
        if (total <= 0) {
            return false;
        }

        auto it = dp.find(bitmask);
        if (it != dp.end()) return it->second;

        bool result = false;
        for (int i = 1; i <= maxInt; ++i) {
            if ((bitmask & (1 << i)) == 0) {
                result = result || !recurse(maxInt, total-i, bitmask | (1 << i), dp);
            }
        }
        
        dp[bitmask] = result;
        return result;
    }
};