class Solution
{
    public:
        string removeStars(string s)
        {
            string ss = "";
            int n = s.size(), stars = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '*')
                {
                    while (i >= 0 && s[i] == '*')
                    {
                        stars += 1;
                        i -= 1;
                    }
                    while (i >= 0 && stars > 0)
                    {
                        
                         if(s[i]!='*') stars -= 1;
                        else stars+=1;
                        i -= 1;
                    }
                     if(i>=0)i+=1;
                }
                else ss+=s[i];
              
            }

            reverse(ss.begin(),ss.end());
            return ss;
        }
};