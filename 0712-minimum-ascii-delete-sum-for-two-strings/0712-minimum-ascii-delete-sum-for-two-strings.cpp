class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=0;
        for(int ind2=1;ind2<=m;ind2++)
        {
            dp[0][ind2]=dp[0][ind2-1]+(int)s2[ind2-1];
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            dp[ind1][0]=dp[ind1-1][0]+(int)s1[ind1-1];
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                int ans=INT_MAX;
                if(s1[ind1-1]==s2[ind2-1])
                {
                    ans = min(ans,dp[ind1-1][ind2-1]);
                }
                else
                {
                    ans = min(ans, s1[ind1-1] +dp[ind1-1][ind2]);
                    ans = min(ans, s2[ind2-1] +dp[ind1][ind2-1]);
                }
                dp[ind1][ind2]=ans;
            }
        }
        return dp[n][m];
    }
};