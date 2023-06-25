class Solution {
public:
    int func1(string &a,string &b){
        int ans=INT_MAX;
        for(char c='a';c<'z';c++){
            int cnt=0;
            for(char x:a){
                cnt+=x>c;
            }
            for(char x:b){
                cnt+=x<=c;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
    int minCharacters(string a, string b) {
        int x=func1(a,b),y=func1(b,a);
        int ans=INT_MAX;
        for(char c='a';c<='z';c++){
            int cnt=0;
            for(char x:a){
                cnt+=x!=c;
            }
            for(char x:b){
                cnt+=x!=c;
            }
            ans=min(ans,cnt);
        }
        return min({x,y,ans});
    }
};