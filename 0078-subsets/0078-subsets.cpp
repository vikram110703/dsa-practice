class Solution {
public:
   void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp){
       int n=nums.size();
       if(ind>=n){
           ans.push_back(tmp);
           // tmp.pop_back();
           return;
       }
       tmp.push_back(nums[ind]);
       solve(ind+1,nums,ans,tmp);
       
       // exclude
       tmp.pop_back();
       solve(ind+1,nums,ans,tmp);
       
   }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        solve(0,nums,ans,tmp);
        return ans;
    }
};