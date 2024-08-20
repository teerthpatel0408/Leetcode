class Solution {
public:
    int func(int idx, int M, vector<int> &piles, int turn, vector<vector<vector<int> > > &dp){
        if(idx >= piles.size()) return 0;
        if(dp[idx][M][turn] != -1){
            return dp[idx][M][turn];
        }
        int alexStones;
        if(turn){
            alexStones = INT_MAX;
            for(int i = 0; i < 2 * M && idx + i < piles.size(); i++){
                alexStones = min(alexStones, func(idx + i + 1, max(M, i + 1), piles, !turn,dp));
            }
            
        }
        else{
            alexStones = 0; int temp = 0;
            for(int i = 0; i < 2 * M && idx + i < piles.size(); i++){
                temp += piles[idx + i];
                alexStones = max(alexStones, temp + func(idx + i + 1, max(M, i + 1), piles, !turn,dp));
            }
        }
            dp[idx][M][turn]=alexStones;
            return alexStones;
        }
    
    
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(105, vector<vector<int> > (105, vector<int> (2, -1)));
        int noOfPiles = piles.size();
        return func(0, 1, piles, 0,dp);
    }
};