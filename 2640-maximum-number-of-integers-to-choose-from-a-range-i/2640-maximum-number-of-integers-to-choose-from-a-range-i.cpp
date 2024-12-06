class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int res=0;
        unordered_set<int>st(banned.begin(),banned.end());
        for(int x=1;x<=n && maxSum>=0;x++){
            if(st.count(x)==0){
                maxSum-=x;
                if(maxSum>=0){
                    res++;
                }
            }
        }
        return res;
    }
};