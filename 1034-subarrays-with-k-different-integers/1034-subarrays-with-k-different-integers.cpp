class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < nums.size(); ++j) {
            if (!count[nums[j]]++) k--;
            while (k < 0) {
                if (!--count[nums[i]]) k++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);

    }
};