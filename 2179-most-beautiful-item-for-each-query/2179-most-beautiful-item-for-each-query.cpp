class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        int n = items.size();
        int q = queries.size();
        vector<pair<int, int>> qq;
        for (int i = 0; i < q; i++) {
            qq.push_back({queries[i], i});
        }
        sort(qq.begin(), qq.end());
        vector<int> ans(q, 0);

        int currMax = 0;
        int j = 0;
        
        for (int i = 0; i < q; i++) {
            int price = qq[i].first;
            int indx = qq[i].second;
            
            while (j < n && items[j][0] <= price) {
                currMax = max(currMax, items[j][1]);
                j++;
            }
            ans[indx] = currMax;
        }

        return ans;
    }
};
