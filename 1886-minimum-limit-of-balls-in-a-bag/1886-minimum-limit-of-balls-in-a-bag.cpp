class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1,right=1e9;
        while(left<=right){
            int mid=(left+right)/2,cnt=0;
            for(int a:nums){
                cnt+=(a-1)/mid;
            }
            if(cnt>maxOperations){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};