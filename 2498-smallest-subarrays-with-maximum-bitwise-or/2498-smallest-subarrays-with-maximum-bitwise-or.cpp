class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> bits(32);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if ((nums[i] & (1 << j)) != 0) {
                    bits[j].push_back(i);
                }
            }
        }

        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            int maxJ = i;
            for (int j = 0; j < 32; j++) {
                auto it = lower_bound(bits[j].begin(), bits[j].end(), i);
                if (it != bits[j].end() && *it == i) {
                    bits[j].erase(it);
                }
            }

            for (int j = 0; j < 32; j++) {
                if ((nums[i] & (1 << j)) != 0)
                    continue;

                else {

                    auto it = upper_bound(bits[j].begin(), bits[j].end(), i);
                    if (it != bits[j].end()) {
                        maxJ = max(maxJ, *it);
                    }
                }
            }

            ans[i] = maxJ - i + 1;
        }

        return ans;
    }
};