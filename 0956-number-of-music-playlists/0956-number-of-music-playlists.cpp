class Solution {
public:
int mod=1e9+7;
    int numMusicPlaylists(int n, int l, int k) {
        vector<vector<long long>>dp(l+1,vector<long long>(n+1));
        dp[0][0]=1;
        for(int i=1;i<=l;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=(dp[i-1][j-1]*(n-j+1))%mod;
                if(j>k){
                    dp[i][j]=(dp[i][j]+(dp[i-1][j]*(j-k))%mod)%mod;
                }
            }
        }
        return (int)dp[l][n];
    }
};