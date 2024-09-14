class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=0,len=0;
        for(int x:nums){
            if(x==maxi){
                ans=max(ans,++len);
            }
            else{
                len=0;
            }
        }
        return ans;
    }
};