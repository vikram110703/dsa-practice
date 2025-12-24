class Solution {
public:
    int lower_bound(int start,int end,vector<int>&nums,int target){
        int mid;
        while(end-start>1)
        {
            mid=start+(end-start)/2;
            if(nums[mid]>=target)
            {
                end=mid;
            }
            else {
                start=mid+1;
            }
        }
        //found ... return first occ
        if(nums[start]==target)return start;
        if(nums[end]==target)return end;

        //not found ... return index of first greater element
        if(nums[start]>target)return start;
        if(nums[end]<target)return end+1;
        return start+1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return{-1,-1};
        int start=0,end=n-1;

        int firstOcc=lower_bound(start,end,nums,target);
        if(firstOcc>=n || nums[firstOcc]!=target)return{-1,-1};
        int lastOcc=lower_bound(start,end,nums,target+1)-1;
        if(nums[lastOcc]!=target)return {firstOcc,firstOcc};
        return {firstOcc,lastOcc};
    }
};