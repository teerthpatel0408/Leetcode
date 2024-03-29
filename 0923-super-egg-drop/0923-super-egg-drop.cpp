class Solution {
public:
    int dps(int k,int n,vector<vector<int>> &dp){
        if(n==0 || n==1){
            return n;
        }
        int ans=INT_MAX,l=1,h=n,temp=0;
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        while(l<=h){
            int mid=(l+h)/2;
            int left=dps(k-1,mid-1,dp);
            int right=dps(k,n-mid,dp);
            temp=1+max(left,right);
            if(left<right){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return dps(k,n,dp);
    }
};