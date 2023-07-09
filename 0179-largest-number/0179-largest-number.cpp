class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(),arr.end(),[](string &s1,string &s2){
            return s1+s2>s2+s1;
        });
        string res;
        for(int s=0;s<arr.size();s++){
            res+=arr[s];
        }
        while(res[0]=='0' && res.length()>1){
            res.erase(0,1);
        }
        return res;
    }
};