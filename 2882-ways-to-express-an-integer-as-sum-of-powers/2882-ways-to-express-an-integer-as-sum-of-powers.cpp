class Solution {
public:
int mod=1e9+7;
    int func(int n,int num,int x,vector<vector<int>>&dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(pow(num,x)>n){
            return 0;
        }
        if(dp[n][num]!=-1){
            return dp[n][num];
        }
        int temp=pow(num,x);
        int take=func(n-temp,num+1,x,dp);
        int nottake=func(n,num+1,x,dp);
        return dp[n][num]=(take%mod + nottake%mod)%mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(301,vector<int>(301,-1));
        return func(n,1,x,dp);
    }
};