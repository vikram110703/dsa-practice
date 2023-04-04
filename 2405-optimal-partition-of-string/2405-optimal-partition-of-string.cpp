class Solution
{
    public:
        int partitionString(string s)
        {
            int n = s.size(),ans=0;vector<int>v(26,0),tmp=v;
            for (int i = 0; i < n; i++)
            {
                v=tmp;
                while (i<n&&v[s[i]-'a'] == 0)
                {
                    v[s[i]-'a'] += 1;
                    i += 1;
                }
                if (i == n)
                {
                    ans += 1;
                    break;
                }
                ans += 1;
                i -= 1;
            }
            v.clear();tmp.clear();
            return ans;
        }
};