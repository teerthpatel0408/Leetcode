class Solution {
public:

    class triple{
        public:
        int node;
        int mask;
        int cost;
        triple(int node,int mask,int cost){
            this->node=node;
            this->mask=mask;
            this->cost=cost;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<triple>q;
        set<pair<int,int>>vis;
        int all=(1<<n)-1;
        for(int i=0;i<n;i++){
            int maskvalue=(1<<i);
            triple thisnode(i,maskvalue,1);
            q.push(thisnode);
            vis.insert({i,maskvalue});
        }

        while(!q.empty()){
            triple curr=q.front();
            q.pop();
            if(curr.mask==all){
                return curr.cost-1;
            }
            for(auto &adj:graph[curr.node]){
                int bothvisited=curr.mask;
                bothvisited=bothvisited | (1<<adj);
                triple thisnode(adj,bothvisited,curr.cost+1);

                if(vis.find({adj,bothvisited})==vis.end()){
                    vis.insert({adj,bothvisited});
                    q.push(thisnode);
                }
            }
        }
        return -1;
    }
};