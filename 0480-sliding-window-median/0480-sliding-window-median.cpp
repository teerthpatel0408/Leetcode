class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash;                          
        priority_queue<int, vector<int>> bheap;                
        priority_queue<int, vector<int>, greater<int>> theap;  
        
        int i = 0;
        
        while (i < k) {
            bheap.push(nums[i++]); 
        }
        for (int count = k/2; count > 0; --count) {
            theap.push(bheap.top()); 
            bheap.pop();
        }
        
        while (true) {
            
            if (k % 2) {
                medians.push_back(bheap.top());
            }
            else {
                medians.push_back( ((double)bheap.top() + theap.top()) / 2 );
            }
            
            if (i == nums.size()) break;
            int m = nums[i-k], n = nums[i++], balance = 0;
            
            if (m <= bheap.top())  { --balance;  if (m == bheap.top()) bheap.pop(); else ++hash[m]; }
            else                   { ++balance;  if (m == theap.top()) theap.pop(); else ++hash[m]; }
            
            if (!bheap.empty() && n <= bheap.top())  { ++balance; bheap.push(n); }
            else                                     { --balance; theap.push(n); }
            
            if      (balance < 0)  { bheap.push(theap.top()); theap.pop(); }
            else if (balance > 0)  { theap.push(bheap.top()); bheap.pop(); }
            
            while (!bheap.empty() && hash[bheap.top()])  { --hash[bheap.top()]; bheap.pop(); }
            while (!theap.empty() && hash[theap.top()])  { --hash[theap.top()]; theap.pop(); }
        }
        
        return medians;
    }
};