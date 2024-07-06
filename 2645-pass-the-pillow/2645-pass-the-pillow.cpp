class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds=time/(n-1);
        int k=time%(n-1);
        return rounds%2==0 ? k+1:n-k;
    }
};