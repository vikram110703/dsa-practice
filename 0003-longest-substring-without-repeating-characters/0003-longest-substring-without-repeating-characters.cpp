class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int n = s.size();
            map<char, int> mpp, tmp;
            int ans = 0;
            int maxi = 0;
            for (int i = 0; i < n; i++)
            {
                maxi = 0;
                for (int j = i; j < n; j++)
                {
                   
                    mpp[s[j]] += 1;
                     if (mpp[s[j]] > 1) break;
                    maxi += 1;
                }
                ans = max(ans, maxi);
                mpp=tmp;
            }
            return ans;
        }
};