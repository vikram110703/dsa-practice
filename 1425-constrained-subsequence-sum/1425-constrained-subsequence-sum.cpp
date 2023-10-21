class Solution {
public:
    
//     int cal(int prev,int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
//         if(dp[ind][prev]!=-1)return dp[ind][prev];
//         if(ind>=nums.size()){
//             return 0;
//         }
//         int take=0,notTake=0;
//         if(ind-prev<=k){
//             take=nums[ind]+cal(ind,ind+1,k,nums,dp);
//         }
//         notTake=cal(prev,ind+1,k,nums,dp);
//         return dp[ind][prev]=max(take,notTake);
        
//     }
    
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        set<pair<int,int>>st;
        st.insert({nums[0],0});
        int ans=nums[0];
        for(int i=1;i<n;i++){
            pair<int,int>p=*st.rbegin();
            while(i-(p.second)>k){
                st.erase(--st.end());
                p=*st.rbegin();
            }
            
            int curr=max(0,p.first)+nums[i];
            ans=max(ans,curr);
            st.insert({curr,i});
        }
        
        return ans;
    }
};