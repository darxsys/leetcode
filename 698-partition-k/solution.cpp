class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        
        if (sum % k != 0) {
            return false;
        }
            
        int target = sum / k;
        vector<int> sums(k, 0);
        return recurse(nums, target, 0, sums);
    }
    
private:
    bool recurse(vector<int>& nums, int target, int cur, vector<int>& sums) {
        if (cur >= nums.size()) return true;
        
        int v = nums[cur++];
        for (int i = 0; i < sums.size(); ++i) {
            if (v + sums[i] <= target) {
                sums[i] += v;
                if (recurse(nums, target, cur, sums)) return true;
                sums[i] -= v;
            }
        }
        
        return false;
    }
};