class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>arr;
        for(int i=0;i<k;i++){
            arr=getmin(nums);
            nums[arr[1]]=arr[0]*multiplier;
        }
        return nums;
    }

    vector<int>getmin(vector<int>nums){
        int mini=INT_MAX;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]<mini){
                mini=nums[j];
                i=j;
            }
        }
        return vector<int>{mini,i};
    }
};