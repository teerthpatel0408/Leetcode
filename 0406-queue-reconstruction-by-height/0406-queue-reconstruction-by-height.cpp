class Solution {
public:
    // bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    //     return (a[0] > b[0] ||(a[0]==b[0] && a[1]<b[1]));
    // }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>result;
        sort(people.begin(),people.end(),[](const vector<int>& a, const vector<int>& b){
            return (a[0] > b[0] ||(a[0]==b[0] && a[1]<b[1]));
        });
        for(vector<int>&x:people){
            result.insert(result.begin()+x[1],x);
        }
        return result;
    }
};