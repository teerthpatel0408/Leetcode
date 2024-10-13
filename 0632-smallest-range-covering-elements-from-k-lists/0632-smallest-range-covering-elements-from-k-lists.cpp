class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>ans;
        for(int k=0;k<nums.size();k++){
            for(auto n:nums[k]){
                ans.push_back({n,k});
            }
        }
        sort(ans.begin(),ans.end());
        int i=0,k=0;
        vector<int>res;
        unordered_map<int,int>cnt;
        for(int j=0;j<ans.size();j++){
            if(!cnt[ans[j].second]++){
                k++;
            }
            if(k==nums.size()){
                while(cnt[ans[i].second]>1){
                    --cnt[ans[i++].second];
                }
                if(res.empty() || res[1]-res[0]>ans[j].first - ans[i].first){
                    res=vector<int>{ans[i].first,ans[j].first};
                }
            }
        }
        return res;
    }
};