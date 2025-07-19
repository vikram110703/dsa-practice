class Solution {
public:
    void dfs(int curr, int n, vector<int>& v) {
        if (curr > n) return;
        v.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            int next = curr * 10 + i;
            if (next > n) break;
            dfs(next, n, v);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for (int i = 1; i <= 9; i++) {
            if (i > n) break;
            dfs(i, n, v);
        }
        return v;
    }
};
