class Solution {
public:
    void setperm(vector<int>&v,string &ans,int n, int k,vector<int>&factval){
        if(n==1){
            ans+=to_string(v.back());
            return;
        }
        int index=(k/factval[n-1]);
        if(k%factval[n-1]==0){
            index--;
        }
        ans+=to_string(v[index]);
        v.erase(v.begin()+index);
        k-=factval[n-1]*index;
        setperm(v,ans,n-1,k,factval);
    }

    string getPermutation(int n, int k) {
        if(n==1){
            return "1";
        }
        vector<int>factval={1,1,2,6,24,120,720,5040,40320,362880};
        string ans="";
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.emplace_back(i);
        }
        setperm(v,ans,n,k,factval);
        return ans;
    }
};