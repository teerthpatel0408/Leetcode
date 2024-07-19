class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxmin=INT_MIN;
        for(int i=0;i<m;i++){
            int Min=INT_MAX;
            for(int j=0;j<n;j++){
                Min=min(Min,matrix[i][j]);
            }
            maxmin=max(maxmin,Min);
        }
        // return vector<int>{maxmin};
        int minmax=INT_MAX;
        for(int j=0;j<n;j++){
            int Max=INT_MIN;
            for(int i=0;i<m;i++){
                Max=max(Max,matrix[i][j]);
            }
            minmax=min(minmax,Max);

        }
        if(maxmin!=minmax){
            return vector<int>{};
        }
        return vector<int>{maxmin};
    }
};