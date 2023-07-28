class Solution
{
    public:
        int chk(vector<int> &nums, vector<vector< int>> &dp, int strt, int end)
        {
            if (strt == end)
            {
                return nums[strt];
            }
            if (dp[strt][end] != -1)
            {
                return dp[strt][end];
            }
            int first = 0, last = 0;
            first = nums[strt] - chk(nums, dp, strt + 1, end);
            last = nums[end] - chk(nums, dp, strt, end - 1);
            dp[strt][end] = max(first, last);
            return dp[strt][end];
        }

    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        int strt = 0, end = n - 1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=chk(nums,dp,0,n-1);
        return ans>=0?true:false;
        
    }
};