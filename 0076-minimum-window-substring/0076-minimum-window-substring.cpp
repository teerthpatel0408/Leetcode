#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return ""; 

        int len = INT_MAX;
        int left = 0, right = 0;
        unordered_map<char, int> tp;
        for (char c : t) tp[c]++;
        
        int count = 0; 
        int startind = -1; 

        while (right < n) {
            if (tp.find(s[right]) != tp.end()) {
                tp[s[right]]--;
                if (tp[s[right]] >= 0) count++;
            }

            while (count == m) { 
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    startind = left;
                }
                if (tp.find(s[left]) != tp.end()) {
                    tp[s[left]]++;
                    if (tp[s[left]] > 0) count--;
                }
                left++;
            }
            right++;
        }
        return (startind == -1) ? "" : s.substr(startind, len);
    }
};