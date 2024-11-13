class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int k = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
            if (j <= k)
            {
                ans += k - j + 1;
            }
        }
        return ans;

    }
};




















/*int countPairSum(int arr[], int L,
                 int R, int N)
{
    
    sort(arr, arr + N);
 
    int right = N - 1, count = 0;
 
    
    while (right > 0) {
 
        
        auto it1
            = lower_bound(arr, arr + N,
                          L - arr[right]);
 
        int start = it1 - arr;
 
        // Ending index of element
        // whose sum with arr[right] <= R
        auto it2
            = upper_bound(arr, arr + N,
                          R - arr[right]);
 
        --it2;
 
        int end = it2 - arr;
 
        // Update the value of end
        end = min(end, right - 1);
 
        // Add the count of elements
        // to the variable count
        if (end - start >= 0) {
            count += (end - start + 1);
        }
 
        right--;
    }
 
    // Return the value of count
    return count;
}*/