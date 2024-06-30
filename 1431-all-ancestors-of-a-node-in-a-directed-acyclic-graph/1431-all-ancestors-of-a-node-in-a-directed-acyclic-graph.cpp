class Solution {
public:
    void dfs(int ind,vector<int> &vis,vector<vector<int>>& edges){
        vis[ind]=1;
        for(auto it: edges[ind]){
            if(vis[it]==0){
                dfs(it,vis,edges);
            }
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& nums) {
        vector<vector<int>> edges(n);
        for(int i=0;i<nums.size();i++){
            edges[nums[i][0]].push_back(nums[i][1]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,vis,edges);
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(vis[j]==1){
                    ans[j].push_back(i);
                }
            }
        }
        return ans;
    }
};