class Solution
{
    public:
        bool canPlaceFlowers(vector<int> &v, int k)
        {
           	// if(n==0)return false;
            if(k==0)return true;
            int n = v.size(), ans = 0;
            if (n == 1)
            {
                if (v[0] == 0 && k == 1) return true;
                else return false;
            }
            if (v[0] == 0 && v[1] == 0)
            {
                ans += 1;
                v[0] = 1;
            }
            for (int i = 1; i < n ; i++)
            {
                if (i + 1 < n)
                {
                    if (v[i] == 0 && v[i - 1] == 0 && v[i + 1] == 0)
                    {
                        ans += 1;
                        v[i] = 1;
                    }
                }
                else
                {
                    if (v[i] == 0 && v[i - 1] == 0)
                    {
                        ans += 1;
                        v[i] = 1;
                    }
                }
            }
            if (ans >= k) return true;
            else return false;
        }
};