class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> a={-1,-1,-1};
        for(int k=0;k<3;k++){
            for(int i=0;i<triplets.size();i++){
                if(triplets[i][k]==target[k] && triplets[i][(k+1)%3]<=target[(k+1)%3] && triplets[i][(k+2)%3]<=target[(k+2)%3]){
                    a[k]=max(a[k],target[k]);
                    a[(k+1)%3]<=target[(k+1)%3];
                    a[(k+2)%3]<=target[(k+2)%3];
                }
            }
        }
        if(a==target){
         return true;
        }

        return false;
    }
};