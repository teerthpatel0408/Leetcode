class Solution {
public:
    int func(vector<int>&cost, vector<int> &time, int i, int walls, vector<vector<int>> &dp) {
        if(walls <= 0) return 0;
        if(i < 0 ) return 1e9;
        if(dp[i][walls] != -1) return dp[i][walls];

        int notTake = 0 + func(cost, time, i - 1, walls, dp);
        int take = cost[i] + func(cost, time, i - 1, walls- time[i] - 1, dp);
        return dp[i][walls] = min(notTake, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(cost,time,n-1,n,dp);
    }
};