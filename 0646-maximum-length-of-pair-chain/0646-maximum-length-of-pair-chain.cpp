class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(n,0);
        if(n==0)
            return 0;
        dp[0] = 1;
        int max_len = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]> pairs[j][1])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            max_len = max(max_len,dp[i]);
        }
        return max_len;
    }
private:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
        
};