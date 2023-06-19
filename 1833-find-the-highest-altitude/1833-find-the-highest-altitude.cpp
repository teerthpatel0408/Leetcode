class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        vector<int> arr;
        arr.push_back(0);
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            arr.push_back(sum);
        }
        sort(arr.begin(),arr.end());
        return arr[arr.size()-1];
    }
};