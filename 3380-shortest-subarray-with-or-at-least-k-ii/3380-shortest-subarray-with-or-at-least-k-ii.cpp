class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int orval=0,ans=INT_MAX;
        vector<int>bits(32,0);
        for(int i=0,j=0;i<nums.size();i++){
            performor(bits,orval,nums[i]);
            if(orval<k){
                continue;
            }
            for(;j<=i && orval>=k;j++){
                reverseor(bits,orval,nums[j]);
                ans=min(ans,i-j+1);
            }
        }
        return ans==INT_MAX ? -1:ans;
    }

    void performor(vector<int>&bits,int &orval,int num){
        orval=orval| num;
        for(int i=0;i<32;i++){
            bits[i]+=(num & (1<<i))?1:0;
        }
    }

    void reverseor(vector<int>&bits,int &orval,int n){
        for(int i=0;i<32;i++){
            bits[i] += (n & (1<<i))?-1:0;
            if(bits[i]==0){
                orval = orval &(~(1<<i));
            }
        }
    }
};