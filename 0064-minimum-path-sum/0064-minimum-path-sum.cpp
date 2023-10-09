class Solution {
public:
    
    int cal(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==0&&row==col)return dp[row][col]=grid[row][col];
        if(row<0||col<0)return INT_MAX;
        if(dp[row][col]!=-1)return dp[row][col];
        
        return dp[row][col]= grid[row][col]+ min(cal(row-1,col,grid,dp),cal(row,col-1,grid,dp));
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return cal(n-1,m-1,grid,dp);
        
    }
};