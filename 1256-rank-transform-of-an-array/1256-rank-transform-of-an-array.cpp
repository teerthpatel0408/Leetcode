class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans(arr);
        sort(ans.begin(),ans.end());
        unordered_map<int,int>mp;
        for( int &a :ans){
            mp.emplace(a,mp.size()+1);
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};