class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(k==1 || k==n){
            return 0;
        }
        vector<int>arr;
        for(int i=0;i<n-1;i++){
            arr.push_back(weights[i]+weights[i+1]);
        }
        sort(arr.begin(),arr.end());
        long long  mins=0,maxs=0;
        for(int i=0;i<k-1;i++){
            mins+=arr[i];
            maxs+=arr[n-2-i];
        }
        return maxs-mins;
    }
};