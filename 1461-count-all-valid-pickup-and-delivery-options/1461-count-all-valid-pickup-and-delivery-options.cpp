class Solution {
public:
    int func(int n,long res){
        return n?func(n-1,res*(n*2-1)*n % long(1e9+7)):res;
    }
    int countOrders(int n) {
        return func(n,1);
    }
};