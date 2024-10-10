class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || A[i] < A[st.top()]) {
                st.push(i);
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && A[i] >= A[st.top()]) {
                ans = max(i - st.top(), ans);
                st.pop();
            }
        }
        return ans;

    }
};