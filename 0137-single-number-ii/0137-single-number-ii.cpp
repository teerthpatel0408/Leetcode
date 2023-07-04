class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>t(32);
        int sz=nums.size();
        int i,j,n;
        for(int i=0;i<sz;i++){
            n=nums[i];
            for(j=31;j>=0;j--){
                t[j]+=n&1;
                n>>=1;
                if(!n){
                    break;
                }
            }
        }
        int res=0;
        for(j=31;j>=0;j--){
            n=t[j]%3;
            if(n){
                res+=1<<(31-j);
            }
        }
        return res;
    }
};