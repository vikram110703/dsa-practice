class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int i=0;
        solve(nums,ans,tmp,i);
        return ans;
    }

    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp,int i){
        if(i>=nums.size()){
            ans.push_back(tmp);
            return;
        }

        // take
        tmp.push_back(nums[i]);
        solve(nums,ans,tmp,i+1);
        tmp.pop_back();

        // not take
        solve(nums,ans,tmp,i+1);
    }
};