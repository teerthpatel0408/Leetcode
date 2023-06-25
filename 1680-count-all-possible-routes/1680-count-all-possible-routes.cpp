class Solution {
public:
    int MOD = 1e9+7;
    
    int dp[101][201];
    int n;
    
    int dfs(vector<int>& locations, int finish, int start, int fuel){
        if(fuel < 0){
            return 0;
        }else if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }else{
            
            int ans = (start == finish);
            
            if(fuel > 0){
                for(int i = 0; i < n; ++i){
                    if(i == start) continue;
                    ans = (ans +dfs(locations, finish, i, fuel - abs(locations[start]-locations[i]))) % MOD;
                }
            }
            
            return dp[start][fuel] = ans;
        }
    };
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(locations, finish, start, fuel);
    }
};