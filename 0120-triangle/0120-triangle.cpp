class Solution {
public:
    vector<vector<int>>dp;
    int INF=1e9;
    int n;
    int limit=-1*1e5;

    int solve(int row,int col,vector<vector<int>>&triangle){
        int maxColRange=row;//see in the triangle,col =row
        if(row>=n || col>maxColRange || col<0) return INF;
        if(row==n-1) return triangle[row][col];
        if(dp[row][col]!=limit)return dp[row][col];

        int op1=solve(row+1,col,triangle);
        int op2=solve(row+1,col+1,triangle);
        return dp[row][col]=triangle[row][col]+min(op1,op2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        dp.resize(n+1,vector<int>(n+1,limit));
        //we can go only (i+1,j) or (i+1,j+1)
        int ans=solve(0,0,triangle);
        return ans;
    }
};