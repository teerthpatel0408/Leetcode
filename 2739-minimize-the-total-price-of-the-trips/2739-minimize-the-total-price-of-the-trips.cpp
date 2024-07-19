class Solution {
public:
    int visited[100];
    vector<int>adj[100];

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        memset(visited,0,sizeof (visited));
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(auto trip:trips){
            int u=trip[0];
            int v=trip[1];
            dfs(u,v);
        }

        pair<int,int>ans=solve(0,-1,price);
        return min(ans.first,ans.second);
    }
    int dfs(int u,int v,int p=-1){
        if(u==v){
            visited[v]++;
            return 1;
        }
        for(auto d:adj[u]){
            if(d==p) continue;
            if(dfs(d,v,u)){
                visited[u]++;
                return 1;
            }
        }
        return 0;
    }

    pair<int,int>solve(int u,int p,vector<int>&price){
        int take=(price[u]/2)*visited[u];
        int nottake = price[u]*visited[u];

        for(auto v:adj[u]){
            if(v==p){
                continue;
            }
            pair<int,int> child=solve(v,u,price);
            nottake+=min(child.first,child.second);
            take+= child.second;
        }
        return {take,nottake};
    }
};