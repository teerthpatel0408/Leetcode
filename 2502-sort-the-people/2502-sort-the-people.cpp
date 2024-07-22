class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>v(names.size());
        for(int i=0;i<names.size();i++){
            v[i]={heights[i],names[i]};
        }
        sort(v.begin(),v.end());
        vector<string>ans(names.size());
        for(int i=names.size()-1;i>=0;i--){
            ans[i]=v[names.size()-i-1].second;
        }
        return ans;

    }
};