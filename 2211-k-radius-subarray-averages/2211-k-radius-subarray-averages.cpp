class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr(n,-1);
        int len=2*k+1;
        if(n<len){
            return arr;
        }
        vector<long>sum(n+1);
        for(int i=0;i<n;i++){
            sum[i+1]=sum[i]+nums[i];
        }
        for(int i=k;i+k<n;i++){
            arr[i]=(sum[i+k+1]-sum[i-k])/len;
        }
        return arr;
    }
};