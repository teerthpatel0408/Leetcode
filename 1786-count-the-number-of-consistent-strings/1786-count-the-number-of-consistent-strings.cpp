class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=words.size();
        bool ans[26]={};
        for(char c:allowed){
            ans[c-'a']=true;
        }
        for(string word:words){
            for(char c:word){
                if(!ans[c-'a']){
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};