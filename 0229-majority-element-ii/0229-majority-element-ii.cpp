class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
           	// Boyer–Moore majority vote algorithm
            int n = nums.size();
            int val = 0, val2 = 0, cnt = 0, cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (val == nums[i]) cnt += 1;
                else if (val2 == nums[i]) cnt2 += 1;
                else if (cnt == 0)
                {
                    val = nums[i];
                    cnt = 1;
                }
                else if (cnt2 == 0)
                {
                    val2 = nums[i];
                    cnt2 = 1;
                }
                else
                {
                    cnt -= 1;
                    cnt2 -= 1;
                }
            }
            cnt = 0, cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == val) cnt += 1;
                if (nums[i] == val2) cnt2 += 1;
            }
            if (cnt > n / 3 && cnt2 > n / 3&&val!=val2) return {
                val,
                val2
            };
            else if (cnt > n / 3) return {
                val
            };
            else if (cnt2 > n / 3) return {
                val2
            };

           else return {};

        }
};