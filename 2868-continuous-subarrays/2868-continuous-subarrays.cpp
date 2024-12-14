class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>1 && mp.rbegin()->first-mp.begin()->first>2 ){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
};