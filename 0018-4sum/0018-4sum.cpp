#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            // if(i!=0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++)
            {
                // if(nums[j]==nums[j-1])continue;
                for(int k=j+1;k<n;k++)
                {
                     long long int sum=(nums[i]*1ll)+(nums[j]*1ll)+(nums[k]*1ll);
                     long long int req=target-sum;
                    auto it=upper_bound(nums.begin(),nums.end(),req)-nums.begin();
                    it--;
                    if(it>k){
                        if(nums[it]==req){
                            st.insert({nums[i],nums[j],nums[k],nums[it]});
                        }
                    }
                }
            }
        }
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
        
    }
};