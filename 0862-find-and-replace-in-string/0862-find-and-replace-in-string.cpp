class Solution {
public:
    string findReplaceString(string str, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>> sorted;
        for(int i=0;i<indices.size();i++){
            sorted.push_back({indices[i],i});
        }
        sort(sorted.rbegin(),sorted.rend());
        for(auto ind:sorted){
            int i=ind.first;
            string s=sources[ind.second],t=targets[ind.second];
            if(str.substr(i,s.length())==s){
                str=str.substr(0,i)+t+str.substr(i+s.length());
            }
        }
        return str;
    }
};