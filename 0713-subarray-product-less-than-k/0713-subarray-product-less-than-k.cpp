class Solution
{
    public:
        int numSubarrayProductLessThanK(vector<int> &nums, int k)
        {
            int n = nums.size();
            long long curr = 1;
            int j = 0, ans = 0;
            for (int i = 0; i < n; i++)
            {
                curr *= nums[i] *1ll;
                if (curr >= k)
                {
                  	
                    while (j <= i && curr >= k)
                    {
                        // cout<<i<<" "<<j<<endl;
                        int len = i - j;
                        ans += len;
                        curr /= nums[j++];
                    }
                    if (j == i && nums[i] >= k)
                    {
                        j += 1;
                    }
                }
                 if (i == n - 1)
                {
                    // cout << j << " " << i << endl;
                    int len = i - j + 1;
                    ans += (len *(len + 1)) / 2;
                }
            }
            return ans;
        }
};