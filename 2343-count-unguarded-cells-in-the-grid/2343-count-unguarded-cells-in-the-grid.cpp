class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int> (n,0));
        int k = walls.size();
        for(int i=0;i<k;i++){
            int x = walls[i][0], y = walls[i][1];
            v[x][y] = -2;
        }
        k = guards.size();
        for(int i=0;i<k;i++){
            int x = guards[i][0], y = guards[i][1];
            v[x][y] = 2;
        }
        for(int j=0;j<k;j++){
            int x = guards[j][0], y = guards[j][1];
            for(int i=x-1;i>=0;i--){
                if(v[i][y]==-2 || v[i][y]==2){
                    break;
                }
                v[i][y] = 1;
            }
            for(int i=x+1;i<m;i++){
                if(v[i][y]==-2 || v[i][y]==2){
                    break;
                }
                v[i][y] = 1;
            }
            for(int i=y-1;i>=0;i--){
                if(v[x][i]==-2 || v[x][i]==2){
                    break;
                }
                v[x][i] = 1;
            }
            for(int i=y+1;i<n;i++){
                if(v[x][i]==-2 || v[x][i]==2){
                    break;
                }
                v[x][i] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!v[i][j]) ans++;
            }
        }
        return ans;
    }
};