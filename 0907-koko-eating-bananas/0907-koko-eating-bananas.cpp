class Solution {
public:

    long long gethour(vector<int>&piles,int bph){
        long long th=0;
        for(int i=0;i<piles.size();i++){
            int h=ceil(piles[i]/(double)bph);
            th+=h;
        }
        return th;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*(max_element(piles.begin(),piles.end()));
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            long long hourstoeat=gethour(piles,mid);
            if(hourstoeat<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};