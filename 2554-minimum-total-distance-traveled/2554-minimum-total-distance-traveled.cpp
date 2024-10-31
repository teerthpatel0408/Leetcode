class Solution {
public:
    long long maxi=1e16;

    long long solve(int i,int j,vector<int>&robot,vector<int>&v,vector<vector<long long>>&dp){
        if(i==robot.size()){
            return 0;
        }
        if(j==v.size()){
            return maxi;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long take = abs(robot[i]-v[j])+solve(i+1,j+1,robot,v,dp);
        long long nottake=solve(i,j+1,robot,v,dp);
        return dp[i][j]=min(take,nottake); 
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>v;
        for(auto i:factory){
            int x=i[0],y=i[1];
            for(int j=0;j<y;j++){
                v.push_back(x);
            }
        }
        vector<vector<long long>>dp(robot.size()+1,vector<long long>(v.size()+1,-1));
        return solve(0,0,robot,v,dp);

    }
};