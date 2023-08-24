class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int n=words.size();
        int len=0,begin=0;
        for(int i=0;i<n;i++){
            if(len+words[i].size()+(i-begin)>maxWidth){
                res.push_back(func(words,maxWidth,begin,i,len,false));
                begin=i;
                len=0;
            }
            len+=words[i].size();
        }
        res.push_back(func(words,maxWidth,begin,n,len,true));
        return res;
    }

    string func(vector<string>& words, int maxWidth,int begin,int end,int len,bool is_last){
        string s;
        int n=end-begin;
        for(int i=0;i<n;i++){
            s+=words[begin+i];
            space(i,n-1,maxWidth-len,is_last,&s);
        }
        if(s.size()<maxWidth){
            s.append(maxWidth-s.size(),' ');
        }
        return s;
    }

    void space(int i,int space,int maxwidth,bool is_last,string *s){
        if(i<space){
            int spaces=is_last?1:maxwidth/space+(i<maxwidth % space);
            s->append(spaces,' ');
        }
    }
};









































