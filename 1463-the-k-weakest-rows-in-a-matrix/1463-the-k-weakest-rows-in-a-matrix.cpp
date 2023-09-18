struct rowinfo{
    int index;
    int count;
};

bool compare(const rowinfo &a,const rowinfo&b){
    if(a.count!=b.count){
        return a.count<b.count;
    }
    return a.index<b.index;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<rowinfo>row(n);
        for(int i=0;i<n;i++){
            row[i].index=i;
            row[i].count=0;
            for(int j=0;j<m;j++){
                row[i].count+=mat[i][j];
            }
        }

        sort(row.begin(),row.end(),compare);
        vector<int>result(k);
        for(int i=0;i<k;i++){
            result[i]=row[i].index;
        }
        return result;
    }
};