class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int ans = 1;
        int prev = pairs[0][1];
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > prev) {
                ans += 1;
                prev = pairs[i][1];
            }
        }
        return ans;
    }
};