class Solution {
public:
    int dp[100001];
    bool winnerSquareGame_help(int n) {
        if(n==0){
            return dp[n]=false;
        }
        if(dp[n]!=-1)   return dp[n];
        int i=1;
        int val=pow(i,2);
        while(val<=n){
            if(!winnerSquareGame_help(n-val))    return dp[n]=true;
            i++;
            val=pow(i,2);
        }
        return dp[n]=false;
    }

    bool winnerSquareGame(int n){
        memset(dp,-1,sizeof(dp));
        return winnerSquareGame_help(n);
    }
};