class Solution {
public: 
    vector<vector<int>>dp;
    int n,m;
    int cal(int i,int j,string &s,string &ss,int currSize){
        if(i>=n||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0,op1=0,op2=0,skip=0;
        if(s[i]==ss[j]){
            take=1+cal(i+1,j+1,s,ss,currSize);
        }
        op1=cal(i+1,j,s,ss,currSize);
        op2=cal(i,j+1,s,ss,currSize);
        skip=cal(i+1,j+1,s,ss,currSize);    
        return dp[i][j]=max({take,op1,op2,skip});
    }
    
    int longestCommonSubsequence(string s, string ss) {
         n=s.size();
         m=ss.size();
       dp.resize(n+1,vector<int>(m+1,-1));
        
        // baseCase
//         for(int i=0;i<=n;i++)dp[i][0]=0;
//         for(int j=0;j<=m;j++)dp[0][j]=0;
      
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(s[i-1]==ss[j-1])
//                 {
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
        
//         return dp[n][m]; // tabulation
        
        int ans=cal(0,0,s,ss,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return ans;
        
    }
};