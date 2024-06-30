class Solution {
public:
    
    int diameter(vector<vector<int>>&edges){
        int n = edges.size() + 1;
            vector<vector<int>> adj(n);
            for (const auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            auto bfs = [&](int start) {
                vector<int> dist(n, -1);
                queue<int> q;
                q.push(start);
                dist[start] = 0;
                int farthest = start;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : adj[node]) {
                        if (dist[neighbor] == -1) {
                            dist[neighbor] = dist[node] + 1;
                            q.push(neighbor);
                            if (dist[neighbor] > dist[farthest]) {
                                farthest = neighbor;
                            }
                        }
                    }
                }
                return make_pair(farthest, dist[farthest]);
            };
        int u = bfs(0).first;
        int diameter = bfs(u).second;
        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
       
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};