class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lower = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        // cout<<lower<<endl;
        if(lower == 0)
        {
            return vector<int>(arr.begin(),arr.begin()+k);
        }
        else if(lower == n)
        {
            return vector<int>(arr.begin()+n-k,arr.end());
        }
        else
        {
            int ptr1 = lower - 1;
            int ptr2 = lower;
            // int count = 1;
            vector<int>ans;
            // ans.push_back(arr[lower]);
            while(k--)
            {
                if(ptr1>=0 && ptr2<n)
                {
                    if(x-arr[ptr1]<=arr[ptr2]-x)
                    {
                        ans.push_back(arr[ptr1]);
                        // cout<<arr[ptr1]<<endl;
                        ptr1--;
                    }
                    else
                    {
                        ans.push_back(arr[ptr2]);
                        // cout<<arr[ptr2]<<endl;
                        ptr2++;
                    }
                }
                else if(ptr1>=0)
                {
                    ans.push_back(arr[ptr1]);
                    // cout<<arr[ptr1]<<endl;
                    ptr1--;
                }
                else if(ptr2<n)
                {
                    ans.push_back(arr[ptr2]);
                    // cout<<arr[ptr2]<<endl;
                    ptr2++;
                }
                // count++;
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
        return {};
    }

};