class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>dp;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            int root = sqrt(i);
            if(root*root==i){
                dp[i]=1+dp[root];
            }
            else{
                dp[i]=1;
            }
            ans=max(ans,dp[i]);
        }
        return ans<2 ? -1:ans;
    }
};