class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        vector<int>lds(n,1);
        for (int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && lis[j]+1>lis[i]){
                    lis[i]=lis[j]+1;
                }
            }
        }

        int maxi=0;
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(nums[i]>nums[j] && lds[j]+1>lds[i]){
                    lds[i]=lds[j]+1;
                }
            }
            if(lis[i]>1 && lds[i]>1){
                maxi=max(maxi,lis[i]+lds[i]-1);
            }
        }
        return n-maxi;
    }
};