class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        for (int i = 0; i < s.size(); ++i) {
            // cout<<r.substr(i)<<endl;
            if (r.substr(i) == s.substr(0, s.size() - i)) {
                return r.substr(0, i) + s;
            }
        }
        return r + s;
    }
};