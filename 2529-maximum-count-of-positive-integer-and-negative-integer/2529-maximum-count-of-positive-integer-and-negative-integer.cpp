class Solution
{
    public:
        int maximumCount(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 1)
            {
                if (nums[0] == 0) return 0;
                else return 1;
            }
            int strt = 0, end = n - 1;
            int mid;
            // find index of first positive 
            while (end - strt > 1)
            {
                mid = strt + (end - strt) / 2;
                if (nums[mid] > 1)
                {
                    end = mid - 1;
                }
                else strt = mid;
            }
            int one = max(strt, end);
            while (one >= 1 && nums[one] > 0)
            {
                one -= 1;
            }

            if (nums[one] <= 0) one += 1;
            strt = 0, end = max(strt, end);
            // find index of last negetive
            while (end - strt > 1)
            {
                mid = strt + (end - strt) / 2;
                if (nums[mid] > -1)
                {
                    end = mid - 1;
                }
                else strt = mid;
            }
            int neg = max(strt, end);
            while (neg >= 0 && nums[neg] >= 0)
            {
                neg -= 1;
            }
// ans=max(n-first pos,last neg+1);
            int ans = max(n - one, neg + 1);
            return ans;
        }
};