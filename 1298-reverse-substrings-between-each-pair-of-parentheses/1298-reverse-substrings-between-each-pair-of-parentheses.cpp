class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>open;
        string ans;
        for (int i=0;i<s.length();i++){
            if(s[i]=='('){
                open.push_back(ans.length());
            }
            else if(s[i]==')'){
                int j=open.back();
                open.pop_back();
                reverse(ans.begin()+j,ans.end());
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};