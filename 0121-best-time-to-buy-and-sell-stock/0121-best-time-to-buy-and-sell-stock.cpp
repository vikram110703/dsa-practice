class Solution {
public:
    //if we sell , we will add money to our ans
    //if we buy, we will decrese the money to our ans
    int solve(int k,int ind,bool buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=prices.size() || k<=0)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];

        int op1=0,op2=0;
        if(buy){
            op1=solve(k,ind+1,buy,prices,dp);
            op2=-prices[ind]+solve(k,ind+1,!buy,prices,dp);
        }
        else{//sell
            op1=solve(k,ind+1,buy,prices,dp);
            op2=prices[ind]+solve(k-1,ind+1,!buy,prices,dp);
        }
        return dp[ind][buy]=max(op1,op2);
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int k=1;//k -> transactions allowed for this k=1
        int ans=solve(k,0,true,prices,dp);
        // return ans; // this is also correct
        return dp[0][1];//dp[0][buy=true]

    }
};