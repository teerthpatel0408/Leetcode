class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B' && st.size() && st.top()=='A'  || s[i]=='D' && st.size() && st.top()=='C'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();

    }
};