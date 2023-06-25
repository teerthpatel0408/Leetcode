#include<bits/stdc++.h>
class Solution {
public:
   
    // int nas=INT_MAX;
    // string concate(string s1, string s2){
    //     if(s1[s1.length() - 1] == s2[0]){
    //         return (s1.substr(0, s1.length() - 1) + s2);
    //     }
    //     return (s1 + s2);
    // }
    // void dp(int i,string s,vector<string>&words){
    //      if(i == words.size()){
    //         if(s.length() < nas){
    //             nas = s.length();
    //         }
    //         return;
    //     }
        
    //     string str1 = concate(s, words[i]);
    //      dp(i + 1, str1, words);
        
    //     //second
    //     string str2 = concate(words[i], s);
    //      dp(i + 1, str2, words);
    // }
    int dp[1001][30][30] = {};

    int solve(vector<string>& words, int i, char firstChar, char lastChar){
        if(i >= words.size()) return 0;
        if(dp[i][firstChar - 'a'][lastChar - 'a'] != 0) return dp[i][firstChar - 'a'][lastChar - 'a'];
        int res1, res2, wordSize = words[i].size();

        //When word is kept first & then the ans string 
        res1 = wordSize + solve(words, i+1, words[i][0], lastChar);
        if(words[i].back() == firstChar) res1--;

        //When word is kept at last after the ans string 
        res2 = wordSize + solve(words, i+1, firstChar, words[i].back());
        if(words[i][0] == lastChar) res2--;

        return dp[i][firstChar - 'a'][lastChar - 'a'] = min(res1, res2);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        return words[0].size() + solve(words, 1, words[0][0], words[0].back());
    }
};