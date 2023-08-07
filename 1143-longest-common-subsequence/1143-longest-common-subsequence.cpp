class Solution {
public:
    int Lcs(int i,int j,string &s,string &ss,vector<vector<int>>&dp)
    {
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==ss[j])
        {
            return dp[i][j]= 1+Lcs(i-1,j-1,s,ss,dp);
        }
        else
        {
            return dp[i][j]= max(Lcs(i-1,j,s,ss,dp),Lcs(i,j-1,s,ss,dp));
        }
        
    }
    
    int longestCommonSubsequence(string s, string ss) {
        int n=s.size(),m=ss.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=Lcs(n-1,m-1,s,ss,dp);
        return ans;
        
    }
};