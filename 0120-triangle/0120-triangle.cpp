class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==0&&j==0)
                {
                    dp[i].push_back(triangle[i][j]);
                }
                else
                {
                    int same=10000 ,prev=10000;
                    if(j-1>=0)
                    {
                        prev=dp[i-1][j-1];
                    }
                    if(j+1<=triangle[i].size()-1)
                    {
                        same=dp[i-1][j];
                    }
                    int val=triangle[i][j]+min(same,prev);
                    dp[i].push_back(val);
                    
                }
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<triangle[n-1].size();j++)
        {
            ans=min(ans,dp[n-1][j]);
        }

        return ans;
    }
};