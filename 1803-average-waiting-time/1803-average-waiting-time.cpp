class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0, cur=0;
        for(int i=0;i<customers.size();i++){
            cur=max(cur,1.0*customers[i][0])+customers[i][1];
            ans+=cur-customers[i][0];
        }
        return 1.0*ans/customers.size();
    }
};