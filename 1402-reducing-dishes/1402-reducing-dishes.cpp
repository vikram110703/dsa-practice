class Solution
{
    public:
        int solve(int ind, int cnt, vector<vector < int>> &dp, vector< int > &v)
        {
            if (ind >= v.size()) return 0;
            if (dp[ind][cnt] != -1) return dp[ind][cnt];

           	// either we will incluce in ans or not include 
            return dp[ind][cnt] = max((v[ind] *cnt) + solve(ind + 1, cnt + 1, dp, v), solve(ind + 1, cnt, dp, v));
        }

    int maxSatisfaction(vector<int> &v)
    {

        int n = v.size();
        sort(v.begin(), v.end());	//max element will get max.. cnt;
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
       	// dp[ind][cnt]--> till index =ind, max possible ans
        int ans = 0;
        if (v[n - 1] <= 0) return ans;
        ans = solve(0, 1, dp, v);

        return ans;
    }
};