class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0, last = max(n, k - 1);
        for (int i = 1; i <= n; ++i) {
            sum += i;
            if (k - i > i && k - i <= n)
                sum += ++last - (k - i);
        }
        return sum;
    }
};