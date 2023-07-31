// typedef long long   ll;
// ll mod = 1000000007;

class Solution {
public:
    unordered_map<string,int>dp;
    int mod=1e9+7;
    int func(string low,string high,int ind,int tight1,int tight2,char prev,int consider){
        int n=low.size();
        if(ind==n){
            return 1;
        }
        string str=to_string(ind)+" "+to_string(tight1)+" "+to_string(tight2)+" "+to_string(prev)+to_string(consider);
        if(dp.count(str)!=0)    return dp[str];
        char l=(tight1==1)?low[ind]:'0';
        char r=(tight2==1)?high[ind]:'9';
        int ans=0;
        for(char c=l;c<=r;c++){
            if(prev!='\0' && consider==1 && abs(prev-c)!=1){
                continue;
            }
            ans+=func(low,high,ind+1,tight1&(c==l),tight2&(c==r),c,consider|(c!='0'));
            ans=ans%mod;
        }
        return dp[str]=ans;
    }
    int countSteppingNumbers(string low, string high) {
        int n1=low.size();
        int n2=high.size();
        int n=n2-n1;
        while(n--){
            low='0'+low;
        }
        return func(low,high,0,1,1,'\0',0)%mod;
    }
};