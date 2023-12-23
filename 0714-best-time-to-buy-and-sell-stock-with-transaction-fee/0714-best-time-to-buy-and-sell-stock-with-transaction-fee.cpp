class Solution {
public:
    vector<vector<int>>dp;
    int cal(int i,int j,vector<int>&prices,int fee){
        int n=prices.size();
        int currProfit=-5*100000;
        if(i>=n) return dp[i][j]=0;
        if(dp[i][j]!=-5*100000)return dp[i][j];
        //j=available stock at the end of the day i
            if(j==0){
                // buy or rest
                currProfit=max(cal(i+1,0,prices,fee),cal(i+1,1,prices,fee)-prices[i]);
            }
            else {
                // sell or rest
            currProfit=max(cal(i+1,1,prices,fee),cal(i+1,0,prices,fee)+prices[i]-fee);
            }
        return dp[i][j]=currProfit;
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-5*100000));
        return cal(0,0,prices,fee);
        
        
    }
};