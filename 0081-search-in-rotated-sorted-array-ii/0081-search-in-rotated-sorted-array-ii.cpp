class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int strt=0,end=n-1,mid;
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            if(nums[mid]==nums[strt]&&nums[mid]==nums[end]){
                end-=1;strt+=1;
            }
            else if(nums[mid]>=nums[strt])//left part is sorted
            {
                if(target>=nums[strt]&&nums[mid]>target)
                {
                    end=mid-1;
                }
                else strt=mid;
            }
            else// right part is sorted
            {
                if(target>nums[mid]&&target<=nums[end])strt=mid+1;
                else end=mid;
                    
            }
            
        }
        if(nums[strt]==target||nums[end]==target)return true;
        else return false;
        
    }
};