class Solution {
public:
    void solve(int ind, int sum, vector<int>& tmp, vector<int>& arr,
               set<vector<int>>& ans) {

        if (sum < 0)
            return;
        if (ind >= arr.size() || sum == 0) {
            if (sum == 0) {
                ans.insert(tmp);
            }
            return;
        }

        solve(ind + 1, sum, tmp, arr, ans);
        // take i freq of ind ...
        for (int i = 1; i <= arr[ind]; i++) {
            tmp.push_back(ind);
            solve(ind + 1, sum -(ind*i), tmp, arr,ans);
        }
        // now pop_back all the pushed values
        while (tmp.size() && tmp.back()==ind) {
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int target) {

        vector<int> tmp;
        set<vector<int>> ans;
        sort(v.begin(), v.end());
        vector<int> arr(51, 0);
        for (auto& val : v)
            arr[val] += 1;
        solve(0, target, tmp, arr, ans);
        vector<vector<int>> res;
        for (auto& val : ans)
            res.push_back(val);
        return res;
    }
};
