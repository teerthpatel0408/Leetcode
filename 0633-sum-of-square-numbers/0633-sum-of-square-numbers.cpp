class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0){
            return false;
        }
        long long left=0,right=sqrt(c);
        while(left<=right){
            long long curr=left*left+right*right;
            if(curr<c){
                left++;
            }
            else if(curr>c){
                right--;
            }
            else{
                return true;
            }
        } 
        return false;
    }
};