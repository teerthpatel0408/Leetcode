class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long cnt[50001]={},ans=0;
        for(auto &r:roads){
            ++cnt[r[0]];
            ++cnt[r[1]];
        }
        sort(begin(cnt),begin(cnt)+n);
        for(int i=0;i<n;i++){
            ans+=cnt[i]*(i+1);
        }
        return ans;
    }
};