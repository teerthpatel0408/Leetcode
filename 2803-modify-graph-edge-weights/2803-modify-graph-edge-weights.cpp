class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> d(n, INT_MAX);
    
        for (auto& e : edges) {
            if (e[2] != -1) {
                graph[e[0]].emplace_back(e[1], e[2]);
                graph[e[1]].emplace_back(e[0], e[2]);
            }
        }
        
        auto dijkstra = [&](int src) {
            fill(d.begin(), d.end(), INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
            d[src] = 0;
            pq.emplace(0, src);
            
            while (!pq.empty()) {
                auto [dist, u] = pq.top();
                pq.pop();
                
                if (dist > d[u]) continue;
                
                for (auto& [v, w] : graph[u]) {
                    if (d[v] > d[u] + w) {
                        d[v] = d[u] + w;
                        pq.emplace(d[v], v);
                    }
                }
            }
        };
        
        dijkstra(source);
        
        if (d[destination] < target) {
            return {};
        }
        
        if (d[destination] == target) {
            for (auto& e : edges) {
                if (e[2] == -1) {
                    e[2] = 1e9;
                }
            }
            return edges;
        }
        
        for (auto& e : edges) {
            if (e[2] == -1) {
                e[2] = 1;
                graph[e[0]].emplace_back(e[1], 1);
                graph[e[1]].emplace_back(e[0], 1);
                
                dijkstra(source);
                
                if (d[destination] <= target) {
                    e[2] += target - d[destination];
                    for (auto& e2 : edges) {
                        if (e2[2] == -1) {
                            e2[2] = 1e9;
                        }
                    }
                    return edges;
                }
            }
        }
        
        return {};
    }
};