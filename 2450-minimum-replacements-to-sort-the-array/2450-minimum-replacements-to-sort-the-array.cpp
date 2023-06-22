class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int len = nums.size(), right = nums[len-1];
        long long res =0 , brk ;
        if(len==1){
            return 0;
        }
        for(int i=len-2;i>=0;i--){
            if(right>=nums[i]){
                right = nums[i];
            }
            else{
                brk = ((nums[i]-1)/right)+1;
                right = nums[i]/brk;
                res +=(brk-1);
            }       
        }
        return res;    
    }
};