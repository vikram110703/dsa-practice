class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int n = chars.size();
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                char a = chars[i];
                while (i + 1 < n && (chars[i] == chars[i + 1]))
                {
                    cnt += 1;
                    i += 1;
                }
                cnt += 1;
                chars[j++] = a;
                // cout << a << " cnt -> " << cnt << endl;

                if (cnt < 10)
                {
                    if (cnt > 1)
                    {
                        
                        chars[j] = (cnt + '0');
                        j+=1;
                    }
                }
                else
                {
                   
                    string s = to_string(cnt);
                    for (int k = 0; k < s.size(); k++)
                    {
                        chars[j] = s[k];
                        j += 1;
                    }
                }
            }
            while (chars.size() > j)
            {
                chars.pop_back();
            }
            return j;
        }
};