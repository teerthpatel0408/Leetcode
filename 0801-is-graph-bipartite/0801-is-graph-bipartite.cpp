class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]){
                continue;
            }
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                for(auto neighbor:graph[temp]){
                    if(!color[neighbor]){
                        color[neighbor]=-color[temp];
                        q.push(neighbor);
                    }
                    else if(color[neighbor]==color[temp]){
                        return false;
                    }
                }

            }
        }
        return true;
    }
};