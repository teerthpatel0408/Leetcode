class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]-k]++;
            mp[nums[i]+k+1]--;
        }
        int mx=0,arr=0;
        for(auto it:mp){
            arr+=it.second;
            mx=max(mx,arr);
        }
        return mx;
    }
};