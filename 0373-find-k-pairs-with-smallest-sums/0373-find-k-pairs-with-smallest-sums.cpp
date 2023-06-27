class Solution {
private:
    // struct mycompare{
    //     bool operator()(pair<int, int>& p1, pair<int, int>& p2){
    //         return p1.first + p1.second < p2.first + p2.second;
    //     }
    // };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>v(n1,1);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=0;i<n1;i++){
            pq.push({nums1[i]+nums2[0],i});
        }
        vector<vector<int>>ans;
        while(k-- && pq.size()!=0){
            pair<long long,int>p=pq.top();
            pq.pop();
            vector<int>vect={nums1[p.second],nums2[v[p.second]-1]};
            ans.push_back(vect);
            if(v[p.second]<n2){
                pq.push({nums1[p.second]+nums2[v[p.second]],p.second});
                v[p.second]++;
            }
        }
        return ans;
    }
    
};