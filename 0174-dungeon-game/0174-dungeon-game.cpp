class Solution {
public:
int func(vector<vector<int>>&mat , vector<vector<int>>&dp,int i=0,int j=0){
    int n=mat.size();
        int m=mat[0].size();

        // int i=0,j=0;
        if(i==n || j==m){
            return 1e9;
        }
        if(i==n-1 && j==m-1){
            return (mat[i][j]<=0)? -mat[i][j]+1 : 1; 
        }
        if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        int right=func(mat,dp,i,j+1);
        int down =func(mat,dp,i+1,j);

        int mini=min(right,down)-mat[i][j];
        return dp[i][j]=mini<=0 ? 1 : mini;
}
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        return func(mat,dp);
    }
};