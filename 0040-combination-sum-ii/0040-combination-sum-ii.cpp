class Solution {
public:
    void solve(int ind, int sum, vector<int>& tmp, vector<int>& v,
               set<vector<int>>& ans, set < pair<vector<int>, int>> & st) {

        if (sum < 0)
            return;
            //check if this index and vector already visited or  not 
        if (st.count({tmp, ind}))
            return;
            st.insert({tmp,ind});
        if (ind >= v.size() || sum == 0) {
            if (sum == 0) {
                ans.insert(tmp);
            }
            return;
        }

        solve(ind + 1, sum, tmp, v, ans,st);
        if (v[ind] <= sum) {
            // take
            tmp.push_back(v[ind]);
            solve(ind + 1, sum - v[ind], tmp, v, ans,st);
            tmp.pop_back(); // backTracking
            // not take
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int target) {

        vector<int> tmp;
        set<vector<int>> ans;
        sort(v.begin(), v.end());
        set<pair<vector<int>,int>>st;
        solve(0, target, tmp, v, ans,st);
        vector<vector<int>> res;
        for (auto& val : ans)
            res.push_back(val);
        return res;
    }
};
