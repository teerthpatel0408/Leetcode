class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0,sum=skill[0]+skill[(int)skill.size()-1];
        int l=0,r=skill.size()-1;
        while(l<r){
            long long s=skill[l]+skill[r];
            ans+=skill[l]*skill[r];
            l++;
            r--;
            if(sum!=s){
                return -1;
            }
        }
        return ans;
    }
};