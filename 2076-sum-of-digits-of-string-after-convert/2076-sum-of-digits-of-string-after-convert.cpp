class Solution {
public:
    int secret(int s){
        int sum=0;
        while(s){
            sum+=s%10;
            s/=10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        int sum=0;
        for(char &ch :s){
            int val=ch-'a' +1;
            sum+= val < 10 ? val : (val%10 + val/10);
        }
        k--;
        while(k-- && sum>=10){
            sum=secret(sum);
        }
        return sum;
    }
};