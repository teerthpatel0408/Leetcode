class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg=0,ans=0,n=matrix.size(),mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    neg+=1;
                }
                mini=mini<abs(matrix[i][j])?mini:abs(matrix[i][j]);
            }
        }
        if(neg%2==0){
            return ans;
        }
        else{
            return ans-2*mini;
        }
    }
};