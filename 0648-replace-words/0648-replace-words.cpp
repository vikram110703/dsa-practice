class Solution
{
    public:
        string replaceWords(vector<string> &d, string s)
        {
            int n = s.size();
            map<string, int> mpp;
            for (auto &it: d)
            {
                mpp[it] += 1;
            }
            string ans = "";
            for (int i = 0; i < n; i++)
            {
                string tmp = "";
                bool found = false;
                while (i<n&&s[i]!=' ')
                {
                    tmp += s[i];
                    if (found == false)
                    {
                        if (mpp.count(tmp))
                        {
                            ans += tmp;
                            found = true;
                        }
                    }
                    i+=1;
                }
                if(!found)ans+=tmp;
                ans+=" ";
            }
            ans.pop_back();
            return ans;
            
        }
};