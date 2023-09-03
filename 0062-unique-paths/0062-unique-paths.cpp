class Solution {
public:
    int nl, ml, dp[105][105];

    bool valid(int x, int y) {
        if(x < nl and y < ml) return true;
        else return false;
    }

    int solve(int i, int j) {
        if(!valid(i, j)) return 0;
        if(i >= nl-1 and j >= ml-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = solve(i+1, j) + solve(i, j+1);
        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {
        nl = m, ml = n;
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0);
        return ans;
    }
};