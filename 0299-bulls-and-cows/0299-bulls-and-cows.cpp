class Solution {
public:
    string getHint(string secret, string guess) {
        int acnt=0;
        int bcnt=0;
        vector<int>s(10,0);
        vector<int>g(10,0);
        if(secret.size()!=guess.size() || secret.empty()){
            return "0A0B";
        }
        for(int i=0;i<secret.size();i++){
            char c1=secret[i],c2=guess[i];
            if(c1==c2){
                ++acnt;
            }
            else{
                ++s[c1-'0'];
                ++g[c2-'0'];
            }
        }
        for(int i=0;i<s.size();i++){
            bcnt+=min(s[i],g[i]);
        }
        return to_string(acnt)+'A'+to_string(bcnt)+'B';
    }
};