class Solution
{
    public:
        string gcdOfStrings(string str1, string str2)
        {
            int n = str1.size();
            int m = str2.size();
            map<string, int> a, b;
            for (int i = 0; i < n; i++)
            {
                string substr = str1.substr(0, i + 1);
                a[substr]++;
                for (int j = i + 1; j < n;j+=i+1 )
                {
                    if (j + i <= n - 1)
                    {
                        string ss = str1.substr(j, i + 1);
                        if(substr==ss)a[substr]++;
                    }
                    
                }
            }

            int maxi = 0;
            string ans = "";
           for (int i = 0; i < m; i++)
            {
                string substr = str2.substr(0, i + 1);
               b[substr]++;
                for (int j = i + 1; j < m; j+=i+1)
                {
                    if (j + i <= m - 1)
                    {
                        string ss = str2.substr(j, i + 1);
                        if(substr==ss)b[substr]++;
                    }
                }
            }
            // for(auto it:a){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            for (auto &it: a)
            {
                string ss = it.first;
                int cnt = it.second, sz = ss.size();
                if (cnt *sz == n)
                {
                    if (b.count(ss))
                    {
                        if (sz *b[ss] == m)
                        {
                            if (sz > maxi)
                            {
                                maxi = sz;
                                ans = ss;
                            }
                        }
                    }
                }
            }
            return ans;
        }
};