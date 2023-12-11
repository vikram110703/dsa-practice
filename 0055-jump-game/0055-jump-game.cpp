class Solution {
public:
    int cal(int ind,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(ind==n-1)return 1;
        if(dp[ind]!=-1)return dp[ind];
        dp[ind]=0;
        for(int i=1;i<=nums[ind];i++){
            int aa=cal(ind+i,nums,dp);
            if(aa==1){dp[ind]=1;break;}
        }
        return dp[ind];
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=cal(0,nums,dp);
        return ans==1;
    }
};