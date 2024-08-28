class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size(),n=grid2[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    ans+=dfs(grid1,grid2,i,j);
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j){
        int m=grid2.size(),n=grid2[0].size(),ans=1;
        if(i<0 || i==m || j<0 || j==n || grid2[i][j]==0){
            return 1;
        }
        grid2[i][j]=0;
        ans&=dfs(grid1,grid2,i-1,j);
        ans&=dfs(grid1,grid2,i+1,j);
        ans&=dfs(grid1,grid2,i,j-1);
        ans&=dfs(grid1,grid2,i,j+1);
        return ans & grid1[i][j];
    }
};