class Solution
{
    public:

        int solve(int currDay, unordered_set<int> &st, vector<int> &cost, vector< int > &dp)
        {
            if (currDay > 365) return 0;
            if (dp[currDay] != -1) return dp[currDay];

            int ans = INT_MAX;
            auto it = st.find(currDay);
            if (it != st.end())
            {
                ans = min({ solve(currDay + 1, st, cost, dp) + cost[0],
                    solve(currDay + 7, st, cost, dp) + cost[1],
                    solve(currDay + 30, st, cost, dp) + cost[2] });
                
            }
            else
            {
                ans = solve(currDay + 1, st, cost, dp);
            }
            dp[currDay] = ans;
            return ans;
        }

    int mincostTickets(vector<int> &days, vector<int> &cost)
    {

        int n = days.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(days[i]);
        }
        vector<int> dp(366,-1);// dp[i]-> total cost to complete all days travel from day i
        

        int ans = solve(1, st, cost, dp);
       	// cout<<dp[1]<<" "<<dp[4]<<" "<<dp[6]<<" "<<dp[7]<<" "<<dp[8]<<" "<<dp[20]<<endl;
        return ans;
    }
};