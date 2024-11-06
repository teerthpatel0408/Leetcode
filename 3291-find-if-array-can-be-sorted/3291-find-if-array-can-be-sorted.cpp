class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>setcnt(n,0);
        for(int i=0;i<n;i++){
            setcnt[i]=__builtin_popcount(nums[i]);
        }

        vector<int>original=nums;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int j=i;
            while(j+1<n && setcnt[j+1]==setcnt[j]){
                j++;
            }
            if(j==n){
                j--;
            }
            if(!check(original,nums,i,j)){
                return false;
            }
            i=j;
        }
        return true;
    }

    bool check(vector<int>&original,vector<int>&nums,int i,int j){
        vector<int>temp1,temp2;
        for(int k=i;k<=j;k++){
            temp1.push_back(original[k]);
            temp2.push_back(nums[k]);
        }
        sort(temp1.begin(),temp1.end());
        return temp1==temp2;
    }
};