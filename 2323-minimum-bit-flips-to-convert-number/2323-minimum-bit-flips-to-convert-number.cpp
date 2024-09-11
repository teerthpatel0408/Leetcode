class Solution {
public:
    int minBitFlips(int start, int goal) {
        int newnum=start^goal,cnt=0;
        while(newnum){
            if(newnum & 1){
                cnt++;
            }
            newnum=newnum>>1;
        }
        return cnt;
    }
};