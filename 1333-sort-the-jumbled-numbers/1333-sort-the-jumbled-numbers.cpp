class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> ans(nums.size()); 
        vector<int> originalNumbers(nums.size()); 
        
        for(int i = 0; i < nums.size(); i++) {
            int transformedNumber = 0;
            int j = nums[i];
            int power = 1; 
            do {
                transformedNumber += mapping[j % 10] * power;
                j /= 10;
                power *= 10;
            } while(j != 0);
            
            ans[i] = {transformedNumber, i}; 
            originalNumbers[i] = nums[i]; 
        }
        
        
        sort(ans.begin(), ans.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; 
            return a.first < b.first;
        });
        
        
        vector<int> sortedArray(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            sortedArray[i] = originalNumbers[ans[i].second];
        }
        return sortedArray;
    }
};