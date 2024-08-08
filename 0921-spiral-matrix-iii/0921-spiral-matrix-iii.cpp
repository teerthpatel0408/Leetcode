class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>res={{rStart,cStart}};
        int dx=0,dy=1,temp;
        for(int n=0;res.size()<rows*cols;n++){
            for(int i=0;i<n/2+1;i++){
                rStart+=dx,cStart+=dy;
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    res.push_back({rStart,cStart});
                }
            }
            temp=dx;
            dx=dy;
            dy=-temp;
        }
        return res;
    }
};