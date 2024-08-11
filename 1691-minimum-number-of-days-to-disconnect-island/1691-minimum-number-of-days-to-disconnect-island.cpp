class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=cnt(grid);
        if(island>1 || island==0){
            return 0;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]){
                        grid[i][j]=0;
                        island=cnt(grid);
                        grid[i][j]=1;
                        if(island>1 || island==0){
                            return 1;
                        }
                    }
                }
            }


        }
        return 2;
    }

    int cnt(vector<vector<int>>&grid){
        int island=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,grid,vis);
                    island++;
                }
            }
        }
        return island;
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    void dfs(int x,int y, vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m &&!vis[nx][ny] && grid[nx][ny]){
                dfs(nx,ny,grid,vis);
            }
        }
    }
};