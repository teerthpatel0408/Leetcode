class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max=0,dp[1<<17]={1};
        for(int a:nums){
            for(int i=max;i>=0;i--){
                dp[i|a]+=dp[i];
                max|=a;
            }
        }
        return dp[max];
    }
};