class Solution
{
    public:
        int numRescueBoats(vector<int> &v, int limit)
        {
            multiset<int> st;
            int n = v.size();
            for (int i = 0; i < n; i++)
            {
                st.insert(v[i]);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int a = v[i];
                auto itt = st.find(a);
                if (itt != st.end())
                {
                    st.erase(itt);
                    auto it = st.upper_bound(limit - a);
                    if (it!=st.begin())
                    {
                        it--;
                        st.erase(it);
                    }
                    ans += 1;
                }
            }

            return ans;
        }
};