class Solution {
public:
    int dp[31][1001];
    int MOD=1000000007;
    int cal(int i,int j,int n,int k){
        //base case 
        if(i==n-1){
            if(j<=k&&j>0){
                // dp[i][target]+=1;
                return 1;
            }
            else return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        long long ans=0;
        for(int val=1;val<=k;val++){
            if(val<=(j)){
                ans=(ans+cal(i+1,j-val,n,k))%MOD;
            }
        }
        return dp[i][j]=ans%MOD;
        
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        for(int i=0;i<n;i++){
            // for(int j=0;j<k;j++){
                for(int jj=0;jj<=1000;jj++)dp[i][jj]=-1;
            }
        // }
        
        int ans=cal(0,target,n,k);
        return ans;
        
    }
};