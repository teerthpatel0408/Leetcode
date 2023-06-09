class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        
        
           while(b) {
            unsigned c = a&b;
            a ^= b;
            b = c << 1;
        }
        return a;
        }
        
        
};