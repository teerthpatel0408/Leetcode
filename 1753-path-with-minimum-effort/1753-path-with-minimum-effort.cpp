class Solution {
public:
    vector<vector<int>>dirs={{-1,0},{0,-1},{0,1},{1,0}};

    bool isvalid(vector<vector<int>>& heights,int mx){
        queue<pair<int,int>>q;
        int row=heights.size();
        int col=heights[0].size();

        vector<vector<bool>>seen(row,vector<bool>(col,false));
        q.push({0,0});
        seen[0][0]=true;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;

            if(r==row-1 && c==col-1){
                return true;
            }
            for(auto& dir:dirs){
                int dr=dir[0]+r;
                int dc=dir[1]+c;
                if(dr<0 || dr>=row || dc<0 || dc>=col || seen[dr][dc]){
                    continue;
                }
                if(abs(heights[r][c]-heights[dr][dc])>mx){
                    continue;
                }
                seen[dr][dc]=true;
                q.push({dr,dc});
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0,r=INT_MAX,best=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(isvalid(heights,mid)){
                r=mid-1;
                best=min(best,mid);
            }
            else{
                l=mid+1;
            }
        }
        return best;

    }
};