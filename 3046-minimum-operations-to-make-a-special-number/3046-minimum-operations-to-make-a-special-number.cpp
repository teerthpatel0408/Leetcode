class Solution {
public:
    int check(string &num,int i){
        for(int j=i-1;j>=0;j--){
            int t=(num[i]-'0')+(num[j]-'0')*10;
            if(t%25==0){
                return num.size()-j-2;
            }
        }
        return num.size();
    }

    int minimumOperations(string num) {
        int n=num.size(),ans=n,i;
        for(i=n-1;i>=0 && num[i]!='0';i--){

        }
        if(i>=0){
            ans=min(n-1,check(num,i));
    }
        for(i=n-1;i>=0 && num[i]!='5';i--){

        }
        return min(ans,check(num,i));
    }
};