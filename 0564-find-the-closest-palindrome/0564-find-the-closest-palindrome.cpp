class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.length()==1){
            return to_string(stoi(n)-1);
        }
        int digit=n.length();
        vector<long>v;
        // cout<<pow(10,digit-1)-1<<endl;
        // cout<<pow(10,digit)+1;
        v.push_back(pow(10,digit-1)-1);
        v.push_back(pow(10,digit)+1);
        int mid=(digit+1)/2;
        long prefix=stol(n.substr(0,mid));
        vector<long>vec={prefix,prefix+1,prefix-1};
        for(long i:vec){
            string postfix=to_string(i);
            if(digit%2!=0){
                postfix.pop_back();
            }
            reverse(postfix.begin(),postfix.end());
            string c=to_string(i)+postfix;
            v.push_back(stol(c));
        }
        long mindiff=LONG_MAX,result,num=stol(n);
        for(int i=0;i<5;i++){
            if(v[i]!=num && abs(v[i]-num)<mindiff){
                mindiff=abs(v[i]-num);
                result=v[i];
            }
            else if(abs(v[i]-num)==mindiff){
                result=min(result,v[i]);
            }

        }
        return to_string(result);
    }
};