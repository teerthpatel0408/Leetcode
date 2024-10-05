class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<s1.length();i++){
            v1[s1[i]-'a']++;
            v2[s1[i]-'a']++;
        }
        int len=s1.length(),original = s1.length();
        int i=0,n=s2.length(),index=0;
        while(i<n){
            if(v2[s2[i]-'a']){
                index = i;
                while(i<n && len){
                    if(v2[s2[i]-'a'])
                    { 
                        v2[s2[i]-'a']--;
                    }
                    else{ 
                        break;
                    }
                    len--;
                    i++;
                }
                if(len==0) {
                    return true;
                }
                len = original;
                i = index;
                v2=v1;
            }
            i++;
        }
        return false;
    }
};

























