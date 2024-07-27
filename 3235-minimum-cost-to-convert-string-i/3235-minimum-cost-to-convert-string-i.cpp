#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long helper2(vector<char>& original, vector<char>& changed, vector<int>& cost, string source, string target) {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        
        // Initialize distances with given costs
        for (int i = 0; i < original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = (long long)cost[i];
        }
        
        // Set diagonal to 0 (cost to convert a character to itself)
        // for (int i = 0; i < 26; i++) {
        //     dist[i][i] = 0;
        // }
        
        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    // if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    // }
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) {
                continue;
            }
            long long curr = dist[source[i] - 'a'][target[i] - 'a'];
            if (curr >= INT_MAX) {
                return -1;
            }
            ans += curr;
        }
        return ans;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        return helper2(original, changed, cost, source, target);
    }
};