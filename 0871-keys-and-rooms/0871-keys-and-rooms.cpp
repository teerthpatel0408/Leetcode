class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            visited.insert(curr);
            for(int k:rooms[curr]){
                if(visited.find(k)==visited.end()){
                    q.push(k);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};