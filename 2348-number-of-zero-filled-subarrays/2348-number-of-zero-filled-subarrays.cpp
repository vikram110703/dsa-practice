class Solution
{
    public:
        long long zeroFilledSubarray(vector<int> &v)
        {
            long long int n = v.size();
            long long int strt = 0, ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                {
                    strt = i;
                    while ((i < n) &&(v[i] == 0))
                    {
                        ans += (i - strt + 1);
                        i += 1;
                    }
                }
            }
            return ans;
        }
};