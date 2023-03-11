#include<bits/stdc++.h>
class Solution
{
    public:

        string invert(string s)
        {
            for (int i = 0; i < s.length(); i++)
            {

                if (s[i] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
            }
            return s;
        }

    string reverse1(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }

    string value(int n, string s)
    {

        if (n == 1)
            return  "0";

        string s1 = value(n - 1, s);
        string s2 = invert(s1);
        string s3 = reverse1(s2);

        string ans= s1 + "1" + s3;
        // ans.erase(ans.begin()+ans.size()-1,1);
        return ans;
    }

   	//...................................................................................

    char findKthBit(int n, int k)
    {

        string ans = value(n, " ");
        // cout<<ans<<endl;
        return ans[k-1];
    }
};