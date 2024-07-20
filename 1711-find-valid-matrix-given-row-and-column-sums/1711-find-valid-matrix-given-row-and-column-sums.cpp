class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size(),n=colSum.size();
        vector<vector<int>> a(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=a[i][j];
                colSum[j]-=a[i][j];
            }
        }
        return a;
    }
};