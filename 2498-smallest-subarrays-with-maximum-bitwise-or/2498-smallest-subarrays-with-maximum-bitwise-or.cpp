class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> last(32, -1); // last occurrence of each bit

        for (int i = n - 1; i >= 0; i--) {
            // Update last occurrence for bits set in nums[i]
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }

            // Find the farthest index we must include
            int maxJ = i;
            for (int b = 0; b < 32; b++) {
                if (last[b] != -1) {
                    maxJ = max(maxJ, last[b]);
                }
            }
            ans[i] = maxJ - i + 1;
        }

        return ans;
    }
};
