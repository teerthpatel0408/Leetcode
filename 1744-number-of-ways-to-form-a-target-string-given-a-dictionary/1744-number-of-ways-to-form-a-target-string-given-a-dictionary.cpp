class Solution {
public:
    vector<vector<int>>dp;
    
    long getcount(vector<string>&words,string &target,int i,int j){
        if(j == target.size()){
            return 1;
        }
        if(i== words[0].size() || words[0].size() - i < target.size() - j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long count = 0;
        for(int idx = 0; idx < words.size(); idx++){
            if(words[idx][i] == target[j]){
                count += getcount(words, target, i + 1, j + 1)%1000000007;
            }
        }
        count += getcount(words, target, i + 1, j)%1000000007;
        return dp[i][j] = count%1000000007;
    }
public:
    int numWays(vector<string>& words, string target) {
        
        dp.resize(words[0].size(), vector<int>(target.size(), -1));
        
        return getcount(words, target, 0, 0);
    }
};