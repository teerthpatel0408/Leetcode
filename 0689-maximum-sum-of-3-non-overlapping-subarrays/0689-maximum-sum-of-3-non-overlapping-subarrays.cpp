class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> W(n - k + 1);
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            if (i >= k) {
                currSum -= nums[i - k];
            }
            if (i >= k - 1) {
                W[i - k + 1] = currSum;
            }
        }

        vector<int> left(W.size());
        int best = 0;
        for (int i = 0; i < W.size(); i++) {
            if (W[i] > W[best]) {
                best = i;
            }
            left[i] = best;
        }

        vector<int> right(W.size());
        best = W.size() - 1;
        for (int i = W.size() - 1; i >= 0; i--) {
            if (W[i] >= W[best]) {
                best = i;
            }
            right[i] = best;
        }
        
        vector<int> ans = {-1, -1, -1};
        for (int j = k; j < W.size() - k; j++) {
            int i = left[j - k], l = right[j + k];
            if (ans[0] == -1 || W[i] + W[j] + W[l] > W[ans[0]] + W[ans[1]] + W[ans[2]]) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }
        return ans;
    }
};