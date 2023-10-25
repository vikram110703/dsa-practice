class Solution {
public:
    int cal(int ind,int reqSum,vector<int>&nums,vector<vector<int>>&dp){
        if(dp[ind][reqSum]!=-1)return dp[ind][reqSum];
        if(ind==nums.size()){
            if(reqSum==0)return 1;
            else return 0;
        }
        
        bool take=0,notTake=0;
        if(nums[ind]<=reqSum)take=cal(ind+1,reqSum-nums[ind],nums,dp);
        notTake=cal(ind+1,reqSum,nums,dp);
        return dp[ind][reqSum]=take|notTake;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum&1)==1)return false;
        vector<vector<int>>dp(n+1,vector<int>(sum,-1));
        int ans=cal(0,sum/2,nums,dp);
        return ans;
        
    }
};