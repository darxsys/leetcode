class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (clips.empty()) return -1;
       
        auto sorting = [](const vector<int>& left, const vector<int>& right) -> bool {
            if (left[0] != right[0]) return left[0] < right[0];
            
            if (left[1] != right[1]) return left[1] < right[1];
            
            return false;
        };
        sort(clips.begin(), clips.end(), sorting);
       
        vector<int> dp(T+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < clips.size(); ++i) {
            int start = min(clips[i][0], T);
            int end = min(clips[i][1], T);
            if (dp[start] < INT_MAX) {
                for (int j = start+1; j <= end; ++j)
                    dp[j] = min(dp[j], dp[start] + 1);
            }
        }
       
        return dp[T] < INT_MAX ? dp[T] : -1;
    }
};