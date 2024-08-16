class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi=0,currmin=100000,currmax=-100000;

        for(auto &a:arrays){
            maxi=max(maxi,max(a.back()-currmin,currmax-a.front()));
            currmin=min(currmin,a.front());
            currmax=max(currmax,a.back());
        }
        return maxi;
    }
};