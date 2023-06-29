class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>graph(n+1);
        for(auto x:roads){
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        } 
        long long inf=1e15;
        long long mod=1e9+7;
        vector<long long> dp(n+1,0);
        vector<long long> dist(n+1,inf);
        priority_queue<pair<long long , long long>>q;
        dist[0]=0;
        dp[0]=1;
        q.push({0,0});

        while(q.size()){
            long long node=q.top().second;
            long long nodewt=-q.top().first;
            q.pop();
            if(dist[node]<nodewt){
                continue;
            }
            for(auto key:graph[node]){
                long long child=key.first;
                long long childwt=key.second;
                if(nodewt+childwt == dist[child]){
                    dp[child]=(dp[child]+dp[node])%mod;
                }
                if(nodewt+childwt < dist[child]){
                    dp[child]=dp[node]%mod;
                    dist[child]=nodewt+childwt;
                    q.push({-dist[child],child});
                }
            }
        }
        return dp[n-1];
    }
};