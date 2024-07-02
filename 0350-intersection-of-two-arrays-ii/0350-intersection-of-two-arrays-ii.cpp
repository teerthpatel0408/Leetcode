class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int num1[1001] = {0};
        int num2[1001] = {0};
        vector<int> arr;

        for(int i =0 ;i<nums1.size();i++){
            num1[nums1[i]]++;
        }

        for(int i =0 ;i<nums2.size();i++){
            num2[nums2[i]]++;
        }

        for(int i =0;i<1001;i++){
            if(num1[i] >0 && num2[i] >0){
                arr.push_back(i);
                num1[i]--;
                num2[i]--;
                i--;
            }
        }
        return arr;
        
    }
};