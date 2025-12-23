class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind, int n, int k, vector<int>& curr) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if (ind > n) return;
        // Pruning: not enough numbers left
        if (curr.size() + (n - ind + 1) < k) return;

        // take
        curr.push_back(ind);
        solve(ind + 1, n, k, curr);
        curr.pop_back();

        // not take
        solve(ind + 1, n, k, curr);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1, n, k, curr);
        return ans;
    }
};
