class Solution
{
    public:
        bool isValid(string s)
        {
            int n = s.size();
            stack<char> st;
            for (int i = 0; i < n; i++)
            {
                if (st.size() == 0)
                {
                    st.push(s[i]);
                   	continue;
                }
                char b = s[i];
                char a = st.top();

                if (a == '(' && b == ')') st.pop();
                else if (a == '[' && b == ']') st.pop();
                else if (a == '{' && b == '}') st.pop();
                else st.push(s[i]);
            }
            bool flg = false;
            if (st.size() == 0) flg = true;
            return flg;
        }
};