class Solution {
public:
   int solve (vector<int>& nums){
        int prev2= 0;
        int prev1= nums[0];
        for (int i=1; i<nums.size(); i++){
            int pick= nums[i]+prev2;
            int notpick= prev1;
            int curr= max(pick,notpick);
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        
        int n= nums.size();
        if (n==1)return nums[0];
        // vector<int> notfirst;
        // vector<int> notlast;
        // for (int i=0; i<n; i++){
        //     if (i!=0)notfirst.push_back(nums[i]);
        //     if (i!=n-1)notlast.push_back(nums[i]);
        // }
        return solve(nums);
    }
};