class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp)
    {
      if(ind>=nums.size())
      {
        ans.push_back(tmp);
          return;
      }
        //take 
        tmp.push_back(nums[ind]);
        solve(ind+1,nums,ans,tmp);
        //not take
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