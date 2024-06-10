class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ans=heights;
        int res=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=ans[i]){
                res++;
            }
        }
        return res;
    }
};