class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0,maxsum=nums[0],curmax=0,minsum=nums[0],curmin=0;
        for(int &a:nums){
            curmax=max(curmax+a,a);
            maxsum=max(maxsum,curmax);
            curmin=min(curmin+a,a);
            minsum=min(minsum,curmin);
            total+=a;
        }
        return maxsum>0?max(maxsum,total-minsum):maxsum;
    }
};