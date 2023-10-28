class Solution {
public:
    
    int cal(int ind,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {        
        if(ind==nums.size()){ 
            if(sum==0)return 0;
            else return INT_MIN;
        }
        
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        int take=INT_MIN,notTake=INT_MIN;
        
        if(nums[ind]<=sum){
            take=1+cal(ind+1,sum-nums[ind],nums,dp);
        }
        notTake=cal(ind+1,sum,nums,dp);
        
        return dp[ind][sum]=max(take,notTake);
        
    }
    
    
    
    int lengthOfLongestSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans=cal(0,k,nums,dp);

        if(ans<=0)return -1;
        else return ans;
        
        
        
  
        
        
    }
};

