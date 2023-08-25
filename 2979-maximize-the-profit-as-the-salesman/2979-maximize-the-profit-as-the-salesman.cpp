class Solution {
public:
int solve(int i,vector<vector<int>>&offer,vector<int>&dp){
    if(i==offer.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int nottake=solve(i+1,offer,dp);
    int low=i+1,high=offer.size()-1;
    int next=offer.size();
    while(low<=high){
        int mid=(high+low)/2;
        if(offer[mid][0]>offer[i][1]){
            high=mid-1;
            next=mid;
        }
        else{
            low=mid+1;
        }
        
    }
    int take=offer[i][2]+solve(next,offer,dp);
    return dp[i]=max(take,nottake);
}
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m=offers.size();
        sort(offers.begin(),offers.end());
        vector<int>dp(m,-1);
        return solve(0,offers,dp);
    }
};