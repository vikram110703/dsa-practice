class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robLinear(nums, 0, n - 2),
                   robLinear(nums, 1, n - 1));
    }

    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;   // dp[i-2]
        int prev1 = 0;   // dp[i-1]

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
