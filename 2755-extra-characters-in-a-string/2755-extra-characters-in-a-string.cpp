class Solution {
public:
    int solve(string &s,unordered_map<string,int>&mp,int i,vector<int>& dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string currstr="";
        int minextra=s.size();
        for(int cur=i;cur<s.size();cur++){
            currstr.push_back(s[cur]);
            int currextra=(mp.count(currstr))?0:currstr.size();
            int next=solve(s,mp,cur+1,dp);
            int total=currextra+next;

            minextra=min(minextra,total);
        }
        return dp[i]=minextra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        vector<int>dp(s.size(), -1);
        for(string &word:dictionary){
            mp[word]++;
        }
        return solve(s,mp,0,dp);
    }
};