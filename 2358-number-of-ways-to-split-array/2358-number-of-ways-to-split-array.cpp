class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right=accumulate(nums.begin(),nums.end(),0LL),left=0,ans=0;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            right-=nums[i];
            ans+=left>=right;
        }
        return ans;
    }
};