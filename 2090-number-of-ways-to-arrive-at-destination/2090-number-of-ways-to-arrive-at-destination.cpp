class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto it:roads)
        {
            long long x = it[0];
            long long y = it[1];
            long long wt = it[2];
            pair<long long,long long> tx = {y,wt};
            pair<long long,long long> ty = {x,wt};
            adj[x].push_back(tx);
            adj[y].push_back(ty);
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;//This stores time taken to reach a particuar node + the nodeval
        vector<long long>dist(n,1e15);
        vector<long long>ways(n,0);
        dist[0] = 0;//distance to reach a start node from start is 0.
        ways[0] = 1;//number of ways to reach start is 1.
        q.push({0,0});//Queue will be storing the time and the nodeval
        long long modu = 1e9+7;
        while(!q.empty())
        {
            long long node = q.top().second;
            long long timeTillNow = q.top().first;
            q.pop();
            for(auto it:adj[node])
            {
                long long val = it.first;
                long long time  = it.second;
                if(timeTillNow + time < dist[val])
                {
                    dist[val] = timeTillNow + time;
                    ways[val] = ways[node];
                    q.push({timeTillNow + time,val});
                }
                else if(timeTillNow + time == dist[val])
                {
                    ways[val] = (ways[val]+ways[node]) % modu;
                }
            }
        }
        return ways[n-1]%modu;
    }
};