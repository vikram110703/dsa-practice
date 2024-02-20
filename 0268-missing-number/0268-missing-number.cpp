class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int curr=0,n=nums.size();
        for(int i=0;i<nums.size();i++)curr+=nums[i];
        int sum=(n*(n+1))/2;
        return sum-curr;
    }
};