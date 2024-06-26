class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>cnt(26,INT_MAX);
        vector<string>ans;
        for(auto s:words){
            vector<int>cnt1(26,0);
            for(auto c:s){
                cnt1[c-'a']++;
            }
            for(auto i=0;i<26;i++){
                cnt[i]=min(cnt[i],cnt1[i]);
            }

        }

        for(auto i=0;i<26;i++){
            for(auto j=0;j<cnt[i];j++){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};