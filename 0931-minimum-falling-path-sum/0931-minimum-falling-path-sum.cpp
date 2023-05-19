class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j]=mat[i][j];
                }
                else
                {
                    int same=INT_MAX,prev=INT_MAX,next=INT_MAX;
                    same=dp[i-1][j];
                    if(j-1>=0)prev=dp[i-1][j-1];
                    if(j+1<=n-1)next=dp[i-1][j+1];
                    dp[i][j]=mat[i][j]+min({same,prev,next});
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        
    }
};