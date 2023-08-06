class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,int>lastseen,maxdiff;
        for(int i=0;i<n;i++){
            if(lastseen.find(nums[i])!=lastseen.end()){
                maxdiff[nums[i]]=max(maxdiff[nums[i]],i-lastseen[nums[i]]-1);
            }
            lastseen[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            maxdiff[nums[i]]=max(maxdiff[nums[i]],(i-lastseen[nums[i]]-1+n)%n);
            lastseen[nums[i]]=i;
        }

        for(auto[k,v]:maxdiff){
            ans=min(ans,v);
        }
        return (ans+1)/2;
    }
};