class Solution {
public:
    //vector<vector<int>>dp(coins.size(), vector<int> (amount, 0));
    int dfs(int amount,vector<int>&coins,int i,int sum,vector<vector<int>>&dp){
        if(sum==amount){
            return 1;
        }
        if(sum>amount || i==coins.size()){
            return 0;
        }
        // if(i==coins.size()){
        //     return 0;
        // }
        if (dp[i][sum]!=-1) {
            return dp[i][sum];
        }
        return dp[i][sum] = dfs(amount, coins, i, sum + coins[i],dp)
                     + dfs(amount, coins, i + 1, sum,dp);
        
       
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int> (amount, -1));
        return dfs(amount,coins,0,0,dp);
    }
};