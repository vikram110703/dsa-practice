class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>tmp;
        solve(nums,ans,tmp,0);
        return ans;
    }

    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp,int strt){
        ans.push_back(tmp);
        for(int i=strt;i<nums.size();i++){
            if(i>strt && nums[i]==nums[i-1])continue;// skip duplicates
            tmp.push_back(nums[i]);
            solve(nums,ans,tmp,i+1);
            //undo changes
            tmp.pop_back();
        }
    }
     
};