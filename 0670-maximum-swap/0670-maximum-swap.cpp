class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.length();
        vector<int>arr(n,-1);
        int curmax=n-1;
        for(int i=n-1;i>=0;i--){
            if(str[i]>str[curmax]){
                curmax=i;
            }
            arr[i]=curmax;
        }
        for(int i=0;i<n;i++){
            if(str[arr[i]]!=str[i]){
                swap(str[i],str[arr[i]]);
                break;
            }
        }
        return stoi(str);
    }
};