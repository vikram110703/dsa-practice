class Solution {
public:
//     int cal(int ind,int reqSum,vector<int>&nums,vector<vector<int>>&dp){
//         if(dp[ind][reqSum]!=-1)return dp[ind][reqSum];
//         if(ind==nums.size()){
//             if(reqSum==0)return 1;
//             else return 0;
//         }
        
//         bool take=0,notTake=0;
//         if(nums[ind]<=reqSum)take=cal(ind+1,reqSum-nums[ind],nums,dp);
//         notTake=cal(ind+1,reqSum,nums,dp);
//         return dp[ind][reqSum]=take|notTake;
        
//     }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum&1)==1)return false;
        
        //base case for tabulation 
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<=sum;j++){
            if(nums[0]==j)dp[0][j]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                bool take=false;
                //req=j-nums[i], we will chk if we get this sum till i-1 index 
                if(j-nums[i]>=0)take=dp[i-1][j-nums[i]];
                // not Take 
                // req sum=j ,we will chk if we get this sum till i-1 index 
                dp[i][j]=dp[i-1][j];
                dp[i][j]|=take;
            }
        }

        return dp[n-1][sum/2];
        
        
    }
};