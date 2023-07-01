class Solution {
public:
unordered_map<string,vector<string>> g;
unordered_set<string> seen;
vector<vector<string>> ans;
    void dfs(string &email){
        seen.insert(email);
        ans.back().push_back(email);
        for(auto &adjemail:g[email]){
            if(!seen.count(adjemail)){
                dfs(adjemail);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &acc:accounts){
            for(int i=2;i<acc.size();i++){
                g[acc[i]].push_back(acc[i-1]);
                g[acc[i-1]].push_back(acc[i]);
            }
        }
        for(auto &acc:accounts){
            if(!seen.count(acc[1])){
                ans.push_back({acc[0]});
                dfs(acc[1]);
                sort(begin(ans.back())+1,end(ans.back()));
            }
        }
        return ans;
    }
};