class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini=INT_MAX,mid=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mini&&nums[i]>mid)return true;
            else if(nums[i]<mini)mini=nums[i];
            else if(nums[i]>mini&&nums[i]<mid)mid=nums[i];
        }
        return false;
    }
};