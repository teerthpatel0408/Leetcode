class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {}, ans = 0;
        unordered_set<int> used;
        for (char ch : s)
            ++cnt[ch - 'a'];
        for (int i = 0; i < 26; ++i){
            for (; cnt[i] > 0 ; --cnt[i]){
                if(used.find(cnt[i])!=used.end())
                    ++ans;
                else {
                    used.insert(cnt[i]);
                    break;
                }    
            }
        }
        return ans;
    }
};
// !used.insert(cnt[i]).second