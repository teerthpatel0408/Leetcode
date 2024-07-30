class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        stack<char>st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                ans++;
            }
            else{
                st.push(s[i]);
            }
        }
        return ans;
    }
};