class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int one=0,inwindow=0,x=0,i=0;
        one=count(nums.begin(),nums.end(),1);
        vector<int>nums2(n*2);
        for(i=0;i<n*2;i++){
            nums2[i]=nums[i%n];
        }
        for(i=0;i<2*n;i++){
            if(i>=one && nums2[i-one]==1){
                x--;
            }
            if(nums2[i]==1){
                x++;
            }
            inwindow=max(x,inwindow);
        }
        return one-inwindow;

    }
};