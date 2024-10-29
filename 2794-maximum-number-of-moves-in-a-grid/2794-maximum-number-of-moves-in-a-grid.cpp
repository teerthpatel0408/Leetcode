class Solution {
public:
    int dfs(int n, int m,vector<vector<int>>& grid,int i, int j, int prev,vector<vector<int>> &memo ){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]<=prev){
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int val=grid[i][j];
        // grid[i][j]=0;
        int ans=max({dfs(n,m,grid,i-1,j+1,val,memo),dfs(n,m,grid,i+1,j+1,val,memo),dfs(n,m,grid,i,j+1,val,memo)})+1;
        return memo[i][j]=ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int res=0;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        for(int i=0;i<n;i++){
            res=max(res,dfs(n,m,grid,i,0,-1e6,memo));

        }
        return res-1;
    }
};