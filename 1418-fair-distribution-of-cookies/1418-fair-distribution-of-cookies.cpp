class Solution {
public:
    int ans=INT_MAX;
    void solve(int start,vector<int> &cookies,vector<int>&v,int k){
        if(start==cookies.size()){
            int maxm=INT_MIN;
            for(int i=0;i<k;i++){
                maxm=max(maxm,v[i]);
            }
            ans=min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i]+=cookies[start];
            solve(start+1,cookies,v,k);
            v[i]-=cookies[start];
        }
    } 
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int> v(k,0);
        solve(0,cookies,v,k);
        return ans;
    }
};