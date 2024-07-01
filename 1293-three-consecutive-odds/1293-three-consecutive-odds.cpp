class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()>=3){
            for(int i=0;i<arr.size()-2;i++){
                if(arr[i]%2==1 && arr[i+1]%2==1 && arr[i+2]%2==1){
                    return true;
                }
            }
        }
        else{
            return false;
        }
        return false;
    }
};