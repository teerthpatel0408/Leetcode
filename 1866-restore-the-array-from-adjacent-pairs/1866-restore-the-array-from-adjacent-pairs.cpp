class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(auto &p:adjacentPairs){
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }

        vector<int>ans;
        for(auto &p:mp){
            if(p.second.size()==1){
                ans.push_back(p.first);
                ans.push_back(p.second[0]);
                break;
            }
        }
        while(ans.size()<adjacentPairs.size()+1){
            auto tail=ans.back(),prev=ans[ans.size()-2];
            auto &next=mp[tail];
            if(next[0]!=prev){
                ans.push_back(next[0]);
            }
            else{
                ans.push_back(next[1]);
            }
        }
        return ans;
    }
};