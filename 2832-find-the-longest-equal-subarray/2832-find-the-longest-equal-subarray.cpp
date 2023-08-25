class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int maxf=0,i=0,n=nums.size();
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++){
            maxf=max(maxf,++mp[nums[j]]);
            if(j-i+1-maxf>k){
                --mp[nums[i++]];
            }
        }
        return maxf;
    }
};