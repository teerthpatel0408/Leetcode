class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1, high=(int)1e5;

        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(mid,quantities,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }

    bool ispossible(int x, vector<int>&quantities,int n){
        for(int i=0;i<quantities.size();i++){
            int p=quantities[i];
            n-=ceil(p/(x*1.0));
            if(n<0){
                return false;
            }
        }
        return true;
    }
};