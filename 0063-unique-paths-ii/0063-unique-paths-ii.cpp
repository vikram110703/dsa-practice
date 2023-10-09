class Solution
{
    
    int cal(int row,int col,vector<vector<int>>&v,vector<vector<int>>&dp){
            if(row==0&&col==row){
                return dp[row][col]=1;
            }
            if(row<0||col<0)return 0; //overFlow
            if(v[row][col]==1)return dp[row][col]=0;//obstacle
            if(dp[row][col]!=-1)return dp[row][col];//memoize
            
            return dp[row][col]=cal(row-1,col,v,dp)+cal(row,col-1,v,dp);
    }
    
    public:
        int uniquePathsWithObstacles(vector<vector < int>> &v)
        {
            int n = v.size(), m = v[0].size();
            if(v[0][0]==1||v[n-1][m-1]==1)return 0;
            
            vector<vector<int>>dp(n,vector<int>(m,-1));
            
            return cal(n-1,m-1,v,dp);
            
        }
};