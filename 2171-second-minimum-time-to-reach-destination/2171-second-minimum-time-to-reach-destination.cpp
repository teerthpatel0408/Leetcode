class Solution {
public:
    int timefunc(int dist,int time,int change){
        int ans=0;
        for(int i=0;i<dist;i++){
            if((ans/change)%2 == 1){
                ans = ((ans/change) + 1)*change;
            }
            // totalTime += time;
            // temp--;
            ans+=time;
        }
        return ans;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>dist(n+1,INT_MAX),dist2(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push({1,0});
        dist[1]=0;

        while(!q.empty()){
            auto [x,d]=q.front();
            q.pop();
            for(int y:adj[x]){
                int nd=d+1;
                if(nd<dist[y]){
                    dist2[y]=dist[y];
                    dist[y]=nd;
                    q.push({y,nd});
                }
                else if(nd>dist[y] && nd<dist2[y]){
                    dist2[y]=nd;
                    q.push({y,nd});
                }
            }
        }

        if(dist2[n]==INT_MAX){
            return -1;
        }
        return timefunc(dist2[n],time,change);

    }
};