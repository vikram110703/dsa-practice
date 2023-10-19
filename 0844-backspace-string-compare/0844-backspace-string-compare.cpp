class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            int n = s.size(), m = t.size();
            int i = n - 1, j = m - 1;
            int last_s = -1, last_t = -1;
            while (i >= 0 || j >= 0)
            {
                while (i >= 0 || j >= 0)
                {
                    while (i >= 0 && (s[i] == '#' || last_s >= 0))
                    {
                        if (s[i] == '#') last_s += 1;
                        else last_s -= 1;
                        i -= 1;
                    }
                    while (j >= 0 && (t[j] == '#' || last_t >= 0))
                    {
                        if (t[j] == '#') last_t += 1;
                        else last_t -= 1;
                        j -= 1;
                    }
                    // cout<<i<<" "<<j<<endl;
                    if (i >= 0 && j >= 0 && s[i] == t[j])
                    {
                        i -= 1;
                        j -= 1;
                    }
                    else break;
                }
                break;
            }
            // cout<<i<<" "<<j<<endl;
            if (i < 0 && j < 0) return true;
            else return false;
        }
};