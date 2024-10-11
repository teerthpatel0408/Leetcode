class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int t_arr=times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>reserved;
        priority_queue<int,vector<int>,greater<int>> avail;
        for(auto &it:times){
            while(!reserved.empty() && reserved.top().first<=it[0]){
                avail.push(reserved.top().second);
                reserved.pop();
            }
            if(it[0]==t_arr){
                break;
            }
            if(avail.empty()){
                reserved.push({it[1],reserved.size()});
            }
            else{
                reserved.push({it[1],avail.top()});
                avail.pop();
            }
        }
        return avail.empty() ? reserved.size():avail.top();
    }
};