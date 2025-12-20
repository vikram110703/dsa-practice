class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()-1)return 0;
        if(dp[ind]!=-1)return dp[ind];

        int ans=nums.size();
        for(int i=0;i<nums[ind];i++){
            ans=min(ans,1+solve(ind+i+1,nums,dp));
        }
        return dp[ind]=ans;
    }

    int jump(vector<int>& nums) {
        // we can solve this uisng dp+segment tree but not the most optimal solution

        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);

    }
};