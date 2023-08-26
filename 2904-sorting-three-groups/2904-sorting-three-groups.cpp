class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(int x:nums){
            a+=x!=1;
            b=min(a,b+(x!=2));
            c=min(b,c+(x!=3));
        }
        return c;
    }
};