class Solution {
public:
    int bestClosingTime(string c) {
        int len=c.size();
        vector<int>y,n;
        y.push_back(0);
        n.push_back(0);
        int cnt=0;
        for(int i=0;i<len;i++){
            if(c[i]=='N'){
                cnt++;
            }
            n.push_back(cnt);
        }
        cnt=0;
        for(int i=len-1;i>=0;i--){
            if(c[i]=='Y'){
                cnt++;
            }
            y.push_back(cnt);
        }
        reverse(y.begin(),y.end());
        int ans=INT_MAX,ind=0;
        for(int i=0;i<len+1;i++){
            int s=y[i]+n[i];
            if(s<ans){
                ans=s;
                ind=i;
            }

        }
        return ind;
    }
};