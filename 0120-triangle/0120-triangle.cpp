class Solution
{
    public:

        int cal(int prev, int row, vector<vector < int>> &tr, vector< vector< int>> &dp)
        {
            if (prev < 0||prev>=tr[row].size()) return INT_MAX;
            int n = tr.size();
            if (row == 0)
            {
                return dp[row][0]= tr[row][0];
            }
            if (dp[row][prev] != INT_MAX) return dp[row][prev];

            int mini = INT_MAX;
       
                int curr = tr[row][prev] + min(cal(prev, row - 1, tr, dp), cal(prev - 1, row - 1, tr, dp));
                mini = min(mini, curr);
            // cout<<row<<" "<<mini<<endl;
            
            return dp[row][prev] = mini;
        }

    int minimumTotal(vector<vector < int>> &tr)
    {

        // int n = tr.size();
        // if(n==1)return tr[0][0];
        // vector<vector < int>> dp(n, vector<int> (n+1 , INT_MAX));
        // int mini=INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //   int curr=cal(i, n-1, tr, dp);
        //     mini=min(mini,curr);
        // }
        // return mini;
        
        //tabulation 
        
        int n=tr.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0){
                    dp[i].push_back(tr[0][0]);
                }
                else{
                    int mini=INT_MAX;
                    if(j!=0){
                        mini=min(mini,tr[i][j]+dp[i-1][j-1]);
                    }
                    if(j!=i){
                        mini=min(mini,tr[i][j]+dp[i-1][j]);
                    }
                    dp[i].push_back(mini);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
       
    }
};