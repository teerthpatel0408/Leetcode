class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()){
            return false;
        }
        int cnt[1001]={0};
        for(int i=0;i<target.size();i++){
            cnt[target[i]]++;
            cnt[arr[i]]--;
        }
        for(int i=0;i<1001;i++){
            if(cnt[i]!=0){
                return false;
            }
        }
        return true;
    }
};