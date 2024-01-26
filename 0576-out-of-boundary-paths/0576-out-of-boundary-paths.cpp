class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    int cal(int i,int j,int k,int m,int n){
        //k -> remaning moves 
        if(i>=m||j>=n||i<0||j<0){
            return 1;
        }
        if(k<=0){
            return 0;
        }
        if(dp[i][j][k]>=0)return dp[i][j][k];
        
        long long  a=0,b=0,c=0,d=0;
        a=(cal(i-1,j,k-1,m,n))%mod;
        b=(cal(i+1,j,k-1,m,n))%mod;
        c=(cal(i,j-1,k-1,m,n))%mod;
        d=(cal(i,j+1,k-1,m,n))%mod;
        return dp[i][j][k]=(a+b+c+d)%mod;
    
    };
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                for(int k=0;k<=50;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        
        int ans=cal(startRow,startColumn,maxMove,m,n);
        
        return ans;
        
    }
};