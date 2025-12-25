class Solution {
public:
    int INF=1e9;
    vector<int>dp;
    int chk(int amount,vector<int>&coins){
        if(amount==0)return 0;
        if(amount<0)return INF;
        if(dp[amount]!=-1)return dp[amount];

        int ans=INF;
        for(auto &coin:coins){
           ans=min(ans,1+chk(amount-coin,coins));
        }
        return dp[amount]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int ans= chk(amount,coins);
        return ans==INF?-1:ans;
    }
};