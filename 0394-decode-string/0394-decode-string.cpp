class Solution {
public:
    string decode(string &s,int &pos){
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            if(cur == '[') {
                string curStr = decode(s,++pos);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else {    
                word += cur;
            }
        }
        return word;
    }

    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
};