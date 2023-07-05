class Solution {
public:
    bool dfs(vector<int>&len, vector<int>&matches,int idx,const int target){
        if(idx==matches.size()){
            return len[0] == len[1] && len[1] == len[2] && len[2] == len[3]; 
        }
        for(int i=0;i<4;i++){
            if(len[i]+matches[idx]>target){
                continue;
            }
            int j=i;
            while(--j>=0){
                if(len[i]==len[j]){
                    break;
                }
            }
            if(j!=-1){
                continue;
            }
            len[i]+=matches[idx];
            if(dfs(len,matches,idx+1,target)){
                return true;
            }
            len[i]-=matches[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4){
            return false;
        }
        int sum=0;
        for(const int val:matchsticks){
            sum+=val;
        }
        if(sum%4!=0){
            return false;
        }
        sort(matchsticks.begin(),matchsticks.end(),[](const int &l,const int &r){
            return l>r;
        });
        vector<int>len(4,0);
        return dfs(len,matchsticks,0,sum/4);
    }
};