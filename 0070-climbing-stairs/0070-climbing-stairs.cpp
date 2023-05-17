class Solution {
public:
    // int ans(vector<int>&dp,int ind,int n)
    // {
    //     if(ind==2)return dp[ind]=2;
    //     if(ind==1)return dp[ind]=1;
    //     if(dp[ind]!=-1)return dp[ind];
    //     dp[ind]=ans(dp,ind-1,n)+ans(dp,ind-2,n);
    //     return dp[ind];
    // }
    
    int climbStairs(int n) {
        // M-1
        // vector<int>dp(n+1,-1);
        // ans(dp,n,n);
        // return dp[n];
        
        // M-2
        vector<int>dp(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(i<=2)
            { 
              if(i==1)dp[i]=1;
                if(i==2)dp[i]=2;
            }
            else
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
        
    }
};