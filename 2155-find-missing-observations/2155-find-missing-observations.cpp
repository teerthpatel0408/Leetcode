class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=mean*(n+m);
        for(int i=0;i<m;i++){
            sum-=rolls[i];
        }
        if(sum<n || sum>6*n){
            return {};
        }
        vector<int>ans(n,sum/n);
        int rem=sum%n;
        for(int i=0;i<rem;i++){
            ans[i]++;
        }
        return ans;
    }
};