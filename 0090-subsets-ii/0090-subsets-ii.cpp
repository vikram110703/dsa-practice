class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;

        calculate(0, nums, tmp, ans);
        return ans;
    }

    void  calculate(int start, vector<int>& nums, vector<int>& tmp,vector<vector<int>>& ans) {
        ans.push_back(tmp);

        for (int i = start; i < nums.size(); i++) {
            // skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            tmp.push_back(nums[i]);
            calculate(i+1,nums,tmp,ans);

            //undo changes
            tmp.pop_back();

        }
    }
};