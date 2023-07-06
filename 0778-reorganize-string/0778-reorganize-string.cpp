class Solution {
public:
    string reorganizeString(string s) {
        vector<int>cnt(26);
        int freq=0,i=0;
        for(char c:s){
            if(++cnt[c-'a']>cnt[freq]){
                freq=(c-'a');
            }
        }
        if(2*cnt[freq]-1>s.size()){
            return "";
        }
        while(cnt[freq]){
            s[i]=('a'+freq);
            i+=2;
            cnt[freq]--;
        }

        for(int j=0;j<26;j++){
            while(cnt[j]){
                if(i>=s.size()){
                    i=1;
                }
                s[i]=('a'+j);
                cnt[j]--;
                i+=2;
            }
        }
        return s;
    }
};