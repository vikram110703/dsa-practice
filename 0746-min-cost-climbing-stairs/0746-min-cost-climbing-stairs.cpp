class Solution {
public:
    
    int cal(int ind,vector<int>&cost,vector<int>&dp){
        int n=cost.size();
        if(ind==n-1){
            return  cost[ind];
        }
        if(ind>=n)return 0;//reach last stair
        if(dp[ind]!=-1)return dp[ind];
        
       return dp[ind]=cost[ind]+min(cal(ind+1,cost,dp),cal(ind+2,cost,dp));
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1)return cost[0];
        vector<int>dp(n,-1);
        return min(cal(0,cost,dp),cal(1,cost,dp));
        
    }
};