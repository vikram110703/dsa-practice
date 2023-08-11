class Solution {
public:
    
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind<0||amount<=0)
        {
           if(amount==0)return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        
        //take 
        int take=f(ind,amount-coins[ind],coins,dp);
        int notTake=f(ind-1,amount,coins,dp);
        return dp[ind][amount]= take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
        
    }
};