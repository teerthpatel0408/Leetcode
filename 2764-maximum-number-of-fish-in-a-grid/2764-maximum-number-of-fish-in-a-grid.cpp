class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
            return 0;
        }
        int fish=grid[r][c];
        grid[r][c]=0;
        vector<vector<int>>move={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<4;i++){
            int newr=r+move[i][0];
            int newc=c+move[i][1];
            fish+=dfs(grid,newr,newc);
        }
        return fish; 
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxfish=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    int fish=dfs(grid,i,j);
                    maxfish=max(fish,maxfish);
                }
            }
        }
        return maxfish;
    }
};