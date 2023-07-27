class Solution {
public:
    long long maxRunTime(int n, vector<int>& ans) {
        sort(ans.begin(),ans.end());
        sort(ans.begin(), ans.end());
        long long sum = accumulate(ans.begin(), ans.end(), 0L);
        int k = 0, na = ans.size();
        while (ans[na - 1 - k] > sum / (n - k))
            sum -= ans[na - 1 - k++];
        return sum / (n - k);
    }
};