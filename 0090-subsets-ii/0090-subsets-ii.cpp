class Solution {
public:
    void print(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&tmp)
    {
        if(ind>=nums.size())
        {
            ans.push_back(tmp);
            return ;
        }
        //take 
        tmp.push_back(nums[ind]);
        print(ind+1,nums,ans,tmp);
        tmp.pop_back();//backTracking
        //not take
        print(ind+1,nums,ans,tmp);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        print(0,nums,ans,tmp);
        set<vector<int>>st;
        for(int i=0;i<ans.size();i++)
        {
            sort(ans[i].begin(),ans[i].end());
            st.insert(ans[i]);
        }
        ans.clear();
        for(auto &it:st)
        {
            ans.push_back(it);
        }
        return  ans;  
    }
};