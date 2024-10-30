class Solution {
public:
    int getLIS(int j,vector<int>&nums)
    {
        int n=nums.size();
        vector<int>LIS;
        for(int i=0;i<j;i++)
        {
            if(LIS.empty())LIS.push_back(nums[i]);
            else
            {
                if(nums[i]>LIS.back())LIS.push_back(nums[i]);
                else
                {
                    auto it=lower_bound(LIS.begin(),LIS.end(),nums[i]);
                    *it=nums[i];
                }
            }
        }
        while(LIS.size()>0 && LIS.back()>=nums[j])LIS.pop_back();
        int removed=(j-LIS.size());
        if(LIS.empty())removed+=1e5;
        LIS.clear();
        for(int i=n-1;i>j;i--)
        {
            if(LIS.empty())LIS.push_back(nums[i]);
            else
            {
                if(nums[i]>LIS.back())LIS.push_back(nums[i]);
                else
                {
                    auto it=lower_bound(LIS.begin(),LIS.end(),nums[i])-LIS.begin();
                   if(it<n) LIS[it]=nums[i];
                }
            }
        }
        while(LIS.size()>0 && LIS.back()>=nums[j])LIS.pop_back();
        removed+=(n-j-1-LIS.size());
        if(LIS.size()==0)removed+=1e5;
        return removed;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int mini=1e5;
        int n=nums.size();

        for(int i=1;i<n-1;i++)
        {
            int curr=getLIS(i,nums);
            // cout<<curr<<": ";
            mini=min(mini,curr);
        }

        return mini;
    }
};