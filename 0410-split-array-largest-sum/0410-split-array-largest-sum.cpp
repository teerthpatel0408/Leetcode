class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int end = accumulate(nums.begin(), nums.end(), 0);
        int start = *max_element(nums.begin(), nums.end()); // Corrected line
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2; // More precise way to avoid potential overflow
            int countSegs = 1;
            int sum = 0;
            int miniSum = INT_MIN;
            for (int num : nums) {
                if (sum + num <= mid) {
                    sum += num;
                } else {
                    countSegs++;
                    miniSum = max(miniSum, sum);
                    sum = num;
                }
            }
            miniSum = max(miniSum, sum);
            if (countSegs > k) {
                start = mid + 1;
            } else {
                ans = min(ans, miniSum);
                end = mid - 1;
            }
        }
        return ans;
    }
};