class Solution {
public:
    //if we sell , we will add money to our ans
    //if we buy, we will decrese the money to our ans
    int solve(int k,int ind,bool buy,vector<int>&prices,vector<vector<vector<int>>>&dp,int &allowedTransaction){
        if(ind>=prices.size() || k>=allowedTransaction)return 0;
        if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];

        int op1=0,op2=0;
        if(buy){
            op1=solve(k,ind+1,buy,prices,dp,allowedTransaction);
            op2=-prices[ind]+solve(k,ind+1,!buy,prices,dp,allowedTransaction);
        }
        else{//sell
            op1=solve(k,ind+1,buy,prices,dp,allowedTransaction);
            op2=prices[ind]+solve(k+1,ind+1,!buy,prices,dp,allowedTransaction);
        }
        return dp[ind][buy][k]=max(op1,op2);
    }

    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k,-1)));
        // dp[ind][buy][k] //maintain 3 states
        int kk=0;
        int ans=solve(kk,0,true,prices,dp,k);
        // return ans; // this is also correct
        return dp[0][1][0];//dp[0][buy=true][kk=0]

    }
};