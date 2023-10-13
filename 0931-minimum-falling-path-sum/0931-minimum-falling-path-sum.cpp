class Solution
{
    public:

        int cal(int row, int ind, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
            int n = matrix.size();
            if (ind < 0 || ind >= n) return INT_MAX;

            if (row == n - 1)
            {
                return dp[row][ind]= matrix[row][ind];
            }

            if (dp[row][ind] != -1) return dp[row][ind];

            return dp[row][ind] = matrix[row][ind] + min({ cal(row + 1, ind, matrix, dp),
                cal(row + 1, ind , matrix, dp),
                cal(row + 1, ind - 1, matrix, dp) });

        }

    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        //MEMOIZATION -> TLE 
        
        
//         int n = matrix.size();
//         vector<vector < int>> dp(n, vector<int> (n, -1));

//         int mini = INT_MAX;
//         for (int j = 0; j < n; j++)
//         {
//             mini = min(mini, cal(0, j, matrix, dp));
//         }

//         return mini;
        
        // TABULATION ....
        
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        
        for(int j=0;j<n;j++)dp[0][j]=matrix[0][j];// base case 
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                if(j-1>=0)mini=min(mini,dp[i-1][j-1]);
                if(j+1<n)mini=min(mini,dp[i-1][j+1]);
                mini=min(mini,dp[i-1][j]);
                
                dp[i][j]=matrix[i][j]+mini;
                
            }
        }
        
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        
        
        
        
        
        
        
    }
};