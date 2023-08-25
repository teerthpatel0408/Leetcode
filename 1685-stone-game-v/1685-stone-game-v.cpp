class Solution {
public:
    int dp[501][501];
    int func(vector<int>& v,int s,int e){
        if(s>e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int r=0,l=0,ans=0;
        for(int i=s;i<=e;i++){
            r+=v[i];
        }
        for(int i=s;i<e;i++){
            l+=v[i];
            r-=v[i];
            if(l<r){
                ans=max(ans,l+func(v,s,i));
            }
            if(l==r){
                ans=max(ans,l+max(func(v,s,i),func(v,i+1,e)));
            }
            if(r<l){
                ans=max(ans,r+func(v,i+1,e));
            }
        }
        return dp[s][e]=ans;
    }
    int stoneGameV(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        return func(v,0,v.size()-1);
    }
};