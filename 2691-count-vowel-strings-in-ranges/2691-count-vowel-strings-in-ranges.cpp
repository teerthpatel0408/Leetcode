class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>vowel({'a','e','i','o','u'});
        vector<int>res,ps;
        ps.push_back(0);
        for(auto &w:words){
            ps.push_back(ps.back()+(vowel.count(w.front()) && vowel.count(w.back())));
        }
        for(auto &q:queries){
            res.push_back(ps[q[1]+1]-ps[q[0]]);
        }
        return res;
    }
};