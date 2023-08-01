class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1,cnt=0;
        while(s[i]==' '){
            i--;
        }
        for(int j=i;j>=0;j--){
            if(s[j]==' '){
                break;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};