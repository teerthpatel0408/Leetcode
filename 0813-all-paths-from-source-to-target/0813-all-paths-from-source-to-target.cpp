class Solution {
public:

    void dfs(vector<vector<int>>&graph,vector<vector<int>>&paths,vector<int>&path,int curr){
        path.push_back(curr);
        if(curr==graph.size()-1){
            paths.push_back(path);

        }
        else {
            for(auto it:graph[curr]){
                dfs(graph,paths,path,it);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>paths;
        vector<int>path;
        dfs(graph,paths,path,0);
        return paths;

    }
};




