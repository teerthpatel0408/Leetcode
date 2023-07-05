class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int cnt0 = 0;
        int l = 0;
        int max_len = 0;

        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0){
                cnt0++;
            }
            
            while(cnt0 > 1) {
                if(nums[l] == 0){
                    cnt0--;
                }
                l++;
            }
            max_len = max(max_len, i - l + 1);
        }
        return max_len-1;
    }
};