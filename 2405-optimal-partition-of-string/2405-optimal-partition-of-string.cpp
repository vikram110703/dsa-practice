class Solution
{
    public:
        int partitionString(string s)
        {
            int n = s.size(),ans=0;
            for (int i = 0; i < n; i++)
            {
                vector<int>v(26,0);
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
                i -= 1;v.clear();
            }
            
            return ans;
        }
};