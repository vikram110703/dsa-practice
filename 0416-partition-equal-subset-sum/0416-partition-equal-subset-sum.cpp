class Solution {
public:
    bool cal(int curr,int ind,vector<int>&nums,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(dp[ind][curr]!=-1)return dp[ind][curr];
        if(ind>=n){
            if(curr==0)return 1;
            return 0;
        }
        
        bool take=false,notTake=false;
        if(curr>=nums[ind])
        take|=cal(curr-nums[ind],ind+1,nums,dp);
        notTake|=cal(curr,ind+1,nums,dp);
        bool res=take|notTake;
        if(res==true){
            dp[ind][curr]=1;
        }
        else dp[ind][curr]=0;
        return dp[ind][curr];
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1==1)return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return cal(sum/2,0,nums,dp);
    
        
    }
};