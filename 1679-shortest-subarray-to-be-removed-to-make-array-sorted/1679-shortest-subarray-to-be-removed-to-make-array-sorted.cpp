class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size=arr.size(),r=size-1;
        for(;r>0 && arr[r-1]<=arr[r];r--);
        auto res=r;
        for(int l=0;l<r&& (l==0 || arr[l-1]<=arr[l]);l++){
            while(r<size && arr[r]<arr[l]){
                r++;
            }
            res=min(res,r-l-1);
        }
        return res;
        

    }
};