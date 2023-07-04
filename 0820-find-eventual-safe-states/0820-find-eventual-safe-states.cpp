class Solution {
public:

    unordered_set<int>safe;
    unordered_set<int>cycle;
    bool dfs(vector<vector<int>>&g,int i, unordered_set<int>visited){
        if(safe.find(i)!=safe.end()){
            return true;
        }
        if(cycle.find(i)!=cycle.end()){
            return false;
        }
        if(visited.find(i)!=visited.end()){
            cycle.insert(i);
            return false;
        }
        visited.insert(i);
        for(int node :g[i]){
            if(!dfs(g,node,visited)){
                cycle.insert(i);
                return false;
            }
        }
        safe.insert(i);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        unordered_set<int> visited;
        for(int i=0;i<graph.size();i++){
            if(dfs(graph,i,visited)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};