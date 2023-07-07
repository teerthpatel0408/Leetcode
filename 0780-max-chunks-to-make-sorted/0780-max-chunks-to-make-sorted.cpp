class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_i=0,ch=0;
        for(int i=0;i<=arr.size();i++){
            if(i==arr.size()){
                return ch;
            }
            max_i=max(max_i,arr[i]);
            if(max_i==i){
                ch++;
            }
        }
        return 0;
    }
};


