class Solution {
public:
    
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> pre;

        for (int num : arr1) {
            string str = to_string(num);
            for (int i = 1; i <= str.length(); ++i) {
                pre[str.substr(0, i)]++;
            }
        }

        int len = 0;
        for (int num : arr2) {
            string str = to_string(num);
            for (int i = 1; i <= str.length(); ++i) {
                if (pre.count(str.substr(0, i))) {
                    len = max(len, i);
                } else {
                    break;
                }
            }
        }

        return len;
    }
};