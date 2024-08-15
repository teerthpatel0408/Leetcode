class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int f=0,t=0,tw=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                f++;
            }
            if(bills[i]==10){
                if(f>=1){
                    f--;
                    t++;
                }
                else{
                    return false;
                }
            }
            if(bills[i]==20){
                if(f>=1 && t>=1){
                    t--;
                    f--;
                    tw++;
                }
                else if(t<1 && f>=3){
                    f-=3;
                    tw++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};