class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n);
        vector<vector<int>>direct(n);
        for(auto &e:edges){
            direct[e[0]].push_back(e[1]);
        }
        for(int i=0;i<n;i++){
            dfs(i,i,ans,direct);
        }
        return ans;

    }

    void dfs(int x,int curr,vector<vector<int>>&ans,vector<vector<int>>&direct){
        for(auto ch:direct[curr]){
            if(ans[ch].size()==0 || ans[ch].back()!=x){
                ans[ch].push_back(x);
                dfs(x,ch,ans,direct);
            }
        }
    }
};