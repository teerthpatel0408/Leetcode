class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int>v;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int diff=abs(nums[i]-nums[j]);
        //         v.push_back(diff);
        //     }
        // }
        // sort(v.begin(),v.end());
        // return v[k-1];

        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid,nums,k)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;

    }

    bool check(int mid,vector<int>&nums,int k){
        int ans=0;
        int j=0,n=nums.size();
        for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i]<=mid){
                j++;
            }
            j--;
            ans+=(j-i);
        }
        return ans>=k;
    }
};