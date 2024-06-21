class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied=0,max_satisfied=0,add_satisfied=0;
        for(auto i=0;i<customers.size();i++){
            satisfied += !grumpy[i]*customers[i];
            add_satisfied += grumpy[i]*customers[i];
            if(i>=minutes){
                add_satisfied -=grumpy[i-minutes]*customers[i-minutes];
            }
            max_satisfied=max(max_satisfied,add_satisfied);
        }
        return satisfied + max_satisfied;
    }
};