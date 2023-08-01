class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        for(;s[i]==' ';i++){}

        if(s[i]=='+' || s[i]=='-'){
            i++;
        }
        int nnm,npt;
        for(nnm=0,npt=0;(s[i]<='9' && s[i]>='0') || s[i]=='.';i++){
            s[i]=='.'?npt++:nnm++;
        }
        if(npt>1 || nnm<1){
            return false;
        }
        if(s[i]=='e' || s[i]=='E'){
            i++;
            if(s[i] == '+' || s[i] == '-') i++; 
        
            int nnm = 0;
            for(; s[i]>='0' && s[i]<='9'; i++, nnm++) {}
            if(nnm<1){
                return false;
            }
        }
        for(; s[i] == ' '; i++) {}
    
        return s[i]==0;
    }
};