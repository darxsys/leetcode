class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) return {};
        
        deque<int> q;
        int n = nums.size();
        for (int i = 0; i < k && i < n; ++i) {
            processQ(nums, q, i, k);
        }
        
        vector<int> result;
        result.reserve(n-k+1);
        result.emplace_back(nums[q.front()]);
        
        for (int i = k; i < n; ++i) {
            processQ(nums, q, i, k);
            result.emplace_back(nums[q.front()]);
        }
        
        return result;
    }
private:
    void processQ(const vector<int>& nums, deque<int>& q, int i, int k) {
        if (q.front() == i - k) {
            q.pop_front();
        }
        
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        
        q.push_back(i);
    }
};