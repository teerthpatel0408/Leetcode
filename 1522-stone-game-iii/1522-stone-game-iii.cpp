class Solution {
public:
int dp[50001];
int helper(vector<int>&v,int i){
    if(i>=v.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    else{
        int ans=INT_MIN;
        ans=max(ans,v[i]-helper(v,i+1));
        if(i+1<v.size()){
            ans=max(ans,v[i]+v[i+1]-helper(v,i+2));
        }
        if(i+2<v.size()){
            ans=max(ans,v[i]+v[i+1]+v[i+2]-helper(v,i+3));
        }
        return dp[i]=ans;
    }
    
}
    string stoneGameIII(vector<int>& s) {
        for(int i=0;i<s.size();i++){
            dp[i]=-1;
        }
        int alice=helper(s,0);
        if(alice>0){
            return "Alice";
        }
        else if(alice<0){
            return "Bob";
        }
        return "Tie";
    }
};