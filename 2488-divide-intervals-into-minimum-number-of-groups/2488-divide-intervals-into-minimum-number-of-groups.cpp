class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        for(auto &v:intervals){
            ans.push_back({v[0],1});
            ans.push_back({v[1]+1,-1});
        }
        int res=0,cur=0;
        sort(ans.begin(),ans.end());
        for(auto &v:ans){
            res=max(res,cur+=v[1]);
        }
        return res;
    }
};