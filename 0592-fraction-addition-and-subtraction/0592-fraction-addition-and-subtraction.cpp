class Solution {
public:
    string fractionAddition(string expression) {
        int nume=0,deno=1,i=0,n=expression.size();
        while(i<n){
            int sign=1;
            if(expression[i]=='+' || expression[i]=='-'){
                if(expression[i]=='-'){
                    sign =-1;
                }
                i++;
            }
            int num=0;
            while(i<n && isdigit(expression[i])){
                num=num*10 + (expression[i]-'0');
                i++;
            }
            num*=sign;
            i++;
            int den=0;
            while(i<n && isdigit(expression[i])){
                den=den*10 + (expression[i]-'0');
                i++;
            }
            nume=nume*den+num*deno;
            deno*=den;
            int gcdval=gcd(abs(nume),deno);
            nume/=gcdval;
            deno/=gcdval;
        }
        return to_string(nume)+"/"+to_string(deno);
    }
};