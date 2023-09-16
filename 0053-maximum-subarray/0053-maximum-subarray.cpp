class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int curr=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0)curr=0;
        }
        return maxi;
    }
};