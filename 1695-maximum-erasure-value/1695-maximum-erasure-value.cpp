class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, int> mpp, tmp;
            int ans = 0, curr = 0, j = 0;
            for (int i = 0; i < n; i++)
            {
               
                while (i < n && mpp[nums[i]] == 0)
                {
                    curr += nums[i];
                    mpp[nums[i]] += 1;
                    i += 1;
                    ans = max(ans, curr);
                }
                if (i == n)
                {
                    ans = max(ans, curr);
                    break;
                }
                ans = max(ans, curr);
                while (j < i && mpp[nums[i]] > 0)
                {
                    curr -= nums[j];
                    mpp[nums[j++]] -= 1;
                }
                i -= 1;
            }
            mpp = tmp;
            return ans;
        }
};