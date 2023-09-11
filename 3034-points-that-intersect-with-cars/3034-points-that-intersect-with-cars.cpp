class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        auto comparator = [] (vector<int>& a, vector<int>& b) {return a[0] < b[0];};
        sort(nums.begin(), nums.end(), comparator);

        int current = 0, ans = 0;
        for (vector<int>& car : nums) {
        if (car[0] > current)
            ans += car[1] - car[0] + 1;
        else if (car[1] > current)
            ans += car[1] - current;

        current = max(current, car[1]);
        }

        return ans; 
    }
};