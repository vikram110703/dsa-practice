class Solution {
public:
    vector<vector<int>>dp;
        int cal(int i,int j,string &s,string &p){
        if(i<0&&j<0)return 1;
        if(i<0&&j>=0){
            while(j>=0&&p[j]=='*')j-=1;
            if(j<0)return 1;
            else return 0;
        } 
        if(j<0&&i>=0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[j]==s[i] || p[j]=='?'){
           return dp[i][j]=cal(i-1,j-1,s,p);

        }
        if(p[j]=='*'){
        int take=cal(i-1,j,s,p);
        int notTake=cal(i,j-1,s,p);
        return dp[i][j]=take|notTake;
        }
        return dp[i][j]=0;
    }
    
        
    bool isMatch(string s, string p) {
       int n=s.size();
       int m=p.size();
       dp.resize(n+1,vector<int>(m+1,-1));
      return  cal(n-1,m-1,s,p); 
    }
};