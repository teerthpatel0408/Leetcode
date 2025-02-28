class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0,cur=0;
        for(int i=0;i<30;i++){
            cur=0;
            for(int a:candidates){
                cur+=a>>i&1;
            }
            res=max(res,cur);
        }
        return res;
    }
};