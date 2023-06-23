class Solution {
public:
    unordered_map<string,bool>mp;
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        if(n==1){
            return s1[0]==s2[0];
        }
        string str=s1+" "+s2;
        if(mp.count(str)!=0)    return mp[str];
        for(int k=0;k<n-1;k++){
            if((isScramble(s1.substr(0,k+1),s2.substr(0,k+1)) && isScramble(s1.substr(k+1,n-k-1),s2.substr(k+1,n-k-1))) || (isScramble(s1.substr(0,k+1),s2.substr(n-k-1,k+1)) && isScramble(s1.substr(k+1,n-k-1),s2.substr(0,n-k-1)))){
                return mp[str]=true;
            }
        }
        return mp[str]=false;
    }
};