class Solution
{
    public:
        void chk(int n, int open, int close, vector<string> &ans, string &s)
        {
            if (open + close >= 2 *n)
            {
                ans.push_back(s);
                return;
            }
            if (open < n)
            {
                s += '(';
                chk(n, open+1, close, ans, s);
                s.pop_back();
            }
            if(close<n&&open>close)
            {
                 s += ')';
                chk(n, open, close+1, ans, s);
                s.pop_back();
            }
        }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s = "";
        int open = 0, close = 0;
        chk(n, open, close, ans, s);
        return ans;
    }
};