class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int helper(vector<int>&arr,int s,int k,vector<int>&dp){
        if(s>=arr.size()){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s];
        }
        int sum=INT_MIN;
        int max_ele=INT_MIN;
        int t=min(s+k,arr.size());
        for(int i=s;i<t;i++){
            max_ele=max(max_ele,arr[i]);
            sum=max(sum,helper(arr,i+1,k,dp)+max_ele*(i-s+1));
        }
        return dp[s]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(arr,0,k,dp);
    }
};