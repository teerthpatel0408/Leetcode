class Solution {
public:
    int f(int i, int j, string& s,vector<vector<int>>&dp){       
        if (dp[i][j]!=-1) return dp[i][j];
        
        if (i==j) return 1;
        
        int ans=INT_MAX; 
        for(int k=i;k<j;k++){
            ans=min(ans,f(i,k,s,dp)+f(k+1,j,s,dp));
        }
        return dp[i][j]=(s[i]==s[j])?ans-1:ans;
    }
    
    int strangePrinter(string s) {
        int n=s.size(); 
        vector<vector<int>>dp(n,vector<int>(n,-1)); 
        return f(0, n-1, s,dp); 
    }
};