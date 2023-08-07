class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=m?board[0].size():0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int a=max(i-1,0);a<min(i+2,m);a++){
                    for(int b=max(j-1,0);b<min(j+2,n);b++){
                        cnt+=board[a][b]&1;
                    }
                }
                if(cnt==3 || cnt-board[i][j]==3){
                    board[i][j]|=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]>>=1;
            }
        }
    }
};