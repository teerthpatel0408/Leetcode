class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<int>>ans(201);
        for(int i=0;i<n;i++){
            ans[a[i]+b[i]].push_back(i);
        }
        bool turn=true;
        int ta=0,tb=0;
        for(int i=200;i>=0;i--){
            for(auto it:ans[i]){
                if(turn){
                    ta+=a[it];
                }
                else{
                    tb+=b[it];
                }
                turn=!turn;
            }
        }
        if(ta>tb){
            return 1;
        }
        else if(tb>ta){
            return -1;
        }
        return 0;

    }
};