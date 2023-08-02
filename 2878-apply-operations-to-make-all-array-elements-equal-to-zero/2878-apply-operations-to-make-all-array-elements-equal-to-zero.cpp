class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int curr=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(curr>nums[i]){
                return false;
            }
            nums[i]-=curr;
            curr+=nums[i];
            if(i>=k-1){
                curr-=nums[i-k+1];
            }
        }
        return curr==0;
    }
};




















