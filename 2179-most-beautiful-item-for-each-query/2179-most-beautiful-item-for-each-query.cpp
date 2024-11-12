class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>ans(queries.size());
        vector<pair<int,int>>queriespair;
        for(int i=0;i<queries.size();i++){
            queriespair.push_back({queries[i],i});
        }
        sort(items.begin(),items.end());
        sort(queriespair.begin(),queriespair.end());

        int item=0,maxbeauty=0;
        for(int i=0;i<queriespair.size();i++){
            int maxprice=queriespair[i].first;
            int index=queriespair[i].second;

            while(item<items.size() && items[item][0]<=maxprice){
                maxbeauty=max(maxbeauty,items[item][1]);
                item++;
            }
            ans[index]=maxbeauty;
        }
        return ans;
    }
};