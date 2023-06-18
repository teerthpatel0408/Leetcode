class Solution {
public:
     int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return dp(nums, memo, 1, n - 2);
    }
private:
    int dp(vector<int>& nums, vector<vector<int>>& memo, int left, int right) {
        if (right - left < 0) {
            return 0;
        }
        if (memo[left][right] > 0) {
            return memo[left][right];
        }
        
        int result = 0;
        for (int i = left; i <= right; i++) {
            
            int curr = nums[left - 1] * nums[i] * nums[right + 1];
            
            int remaining = dp(nums, memo, left, i - 1) + dp(nums, memo, i + 1, right);
            result = max(result, curr + remaining);
        }
        
        memo[left][right] = result;
        return result;
    }
};