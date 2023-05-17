class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=1;continue;
                }
                
                int upper=0,left=0;
                if(i-1>=0)
                {
                    upper=dp[i-1][j];
                }
                if(j-1>=0)
                {
                    left=dp[i][j-1];
                }
                dp[i][j]=upper+left;
            }
        }
        int ans=0;
        if(n-2>=0)ans+=dp[n-2][m-1];
        if(m-2>=0)ans+=dp[n-1][m-2];
        return max(ans,1);
        
    }
};