class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        map<int, int> m;
        for (auto& val : barcodes)
            m[val]++;

        vector<pair<int, int>> v;
        for (auto& val : m)
            v.push_back({val.second, val.first});

        sort(v.begin(), v.end());

        vector<int> ans;
        int i = 0, j = v.size() - 1;
        while (i < v.size() && i < j) {
            while (v[i].first > 0 && v[j].first > 0) {
                ans.push_back(v[j].second);
                ans.push_back(v[i].second);
                v[i].first -= 1;
                v[j].first -= 1;
            }
            if (v[i].first == 0)
                i += 1;
            if (v[j].first == 0)
                j -= 1;
        }
        int sz = barcodes.size();
        //now put all the remaining elements in the vector 
        int cnt = 0;// count  elements which are same 
        while (i < sz && v[i].first > 0) {
            ans.push_back(v[i].second);
            v[i].first -= 1;
        }
        while (j >= 0 && v[j].first > 0) {
            ans.push_back(v[j].second);
            v[j].first -= 1;
        }
        for(int i=0;i<sz-1;i++)
        {
            if(ans[i]==ans[i+1])cnt+=1;
        }
        cnt+=1;// same values in the last
        i = 0, j = sz - 1;
        if(cnt&1)j=sz-2;
        while (i < sz && i < j &&(ans[j] == ans[j - 1] ||(j + 1 < sz - 1 && ans[j] == ans[j + 1]))) {
            swap(ans[i], ans[j]);
            if (ans[j] == ans[j - 1]) j -= 1;
            else j -= 2;
            i += 3;
        }
        return ans;
    }
};
