class Solution {
public:
    vector<string> output;
    void letter(string ip,int len,string op,map<char,string> &mp)
    {
        if(len==0)
        {
            reverse(op.begin(),op.end());
            output.push_back(op);
            return ;
        }
        for(auto i: mp[ip[len-1]])
        {
            string op1=op+i;
            letter(ip,len-1,op1,mp);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return output;
        }
        map<char ,string> mp={{'1',""},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8', "tuv"},{'9',"wxyz"}};
        letter(digits,digits.size(),"",mp);
        return output;
    }
};