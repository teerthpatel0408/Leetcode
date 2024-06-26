class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        // for(int i = 0;i<n;i+=n-1)
        // {
        //     for(int j = 0;j<m;j++)
        //     {
        //         if(board[i][j] == 'O' && visited[i][j] == false)
        //         {
        //             q.push({i,j});
        //             visited[i][j] = true;
        //         }
        //     }
        // }
        // for(int i = 0;i<m;i+=m-1)
        // {
        //     for(int j = 0;j<n;j++)
        //     {
        //         if(board[j][i] == 'O' && visited[j][i] == false)
        //         {
        //             q.push({j,i});
        //             visited[j][i] = true;
        //         }
        //     }
        // }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                visited[0][i] = true;
            }
            if(board[n-1][i] == 'O'){
                q.push({n-1,i});
                visited[n-1][i] = true;
            }
        }
        for(int i = 1; i < n-1; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                visited[i][0] = true;
            }
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
                visited[i][m-1] = true;
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int row = x + dx[i];
                int col = y + dy[i];
                if(row>=0 && col >=0 && row <n && col <m && board[row][col] == 'O' && !visited[row][col])
                {
                    q.push({row,col});
                    visited[row][col]=true;
                    
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j] == 'O')    
                    board[i][j] = 'X';
            }
        }
    }
};