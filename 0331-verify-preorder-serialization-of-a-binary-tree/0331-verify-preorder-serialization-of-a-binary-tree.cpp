class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()){
            return false;
        }
        preorder+=',';
        int n=preorder.size(),idx=0;
        int cap=1;
        for(idx=0;idx<n;idx++){
            if(preorder[idx]!=',')continue;
            cap--;
            if(cap<0){
                return false;
            }
            if(preorder[idx-1]!='#'){
                cap+=2;
            }
        }
        return cap==0;
    }
};