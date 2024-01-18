class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    int cal(int i,int j,string &s,string &t){
        if(i>=n){
            if(j>=m)return 1;
            else return 0;
        }
        if(j>m)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0,notTake=0;
        if(s[i]==t[j]){
             take=cal(i+1,j+1,s,t);
        }
        notTake= cal(i+1,j,s,t);
        return dp[i][j]=take+notTake;
        
    }
    
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int ans=cal(0,0,s,t);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return ans;
    }
};