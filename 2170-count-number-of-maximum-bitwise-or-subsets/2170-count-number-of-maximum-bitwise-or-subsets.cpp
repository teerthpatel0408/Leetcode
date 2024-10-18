class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int goal = 0, N = nums.size(), ans = 0;
        for (int n : nums){
            goal |= n;
        }
        for (int m = 1; m < 1 << N; ++m){
            int x = 0;
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) x |= nums[i];
            }
            if (x == goal){
                ans++;
            }
        }
        return ans;
    }
};