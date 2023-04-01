class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int strt=0,end=n-1;
        int mid;
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            if(nums[mid]>target)end=mid-1;
            else strt=mid;
        }
        if(nums[strt]==target)return strt;
        if(nums[end]==target)return end;
        return -1;
        
    }
};