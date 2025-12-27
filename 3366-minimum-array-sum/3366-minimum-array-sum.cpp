class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<int>& nums, int k, int idx, int op1, int op2) {
        if (idx == n) return 0;

        if (dp[idx][op1][op2] != -1)
            return dp[idx][op1][op2];

        int ans = INT_MAX;

        // CASE-1 : apply op1 (ceil divide by 2)
        if (op1 > 0) {
            int afterOp1 = (nums[idx] + 1) / 2;
            ans = min(ans, afterOp1 + solve(nums, k, idx + 1, op1 - 1, op2));
        }

        // CASE-2 : apply op2 (subtract k)
        if (op2 > 0 && nums[idx] >= k) {
            ans = min(ans, (nums[idx] - k) + solve(nums, k, idx + 1, op1, op2 - 1));
        }

        // CASE-3 & CASE-4 : both operations
        if (op1 > 0 && op2 > 0) {
            // op1 -> op2
            int afterOp1 = (nums[idx] + 1) / 2;
            if (afterOp1 >= k) {
                ans = min(ans,
                          (afterOp1 - k) +
                          solve(nums, k, idx + 1, op1 - 1, op2 - 1));
            }

            // op2 -> op1
            if (nums[idx] >= k) {
                int afterOp2 = nums[idx] - k;
                int afterOp2Op1 = (afterOp2 + 1) / 2;
                ans = min(ans,
                          afterOp2Op1 +
                          solve(nums, k, idx + 1, op1 - 1, op2 - 1));
            }
        }

        // CASE-5 : no operation
        ans = min(ans, nums[idx] + solve(nums, k, idx + 1, op1, op2));

        return dp[idx][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        dp.assign(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return solve(nums, k, 0, op1, op2);
    }
};
