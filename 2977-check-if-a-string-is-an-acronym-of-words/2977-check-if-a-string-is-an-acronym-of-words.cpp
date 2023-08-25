class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n=words.size();
        string ans;
        for(int i=0;i<n;i++){
            ans+=words[i][0];
        }
        return ans==s;
    }
};