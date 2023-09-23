class Solution {
public:
static bool cmp(string &first, string & second){
    return first.size()<second.size();
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        map<string,int> my;
        int res=0;
        for(string word:words){
            int longe=0;
            for(int i=0;i<word.length();i++){
                string sub=word.substr(0,i)+word.substr(i+1,word.length()+1);
                longe=max(longe,my[sub]+1);
            }
            my[word]=longe;
            res=max(res,longe);
        }
        return res;
    }
};