class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int strt=0,end=n-1,mid;
        int index=0;
        if(n==1)
        {
            if(nums[0]==target)
            {
                return 0;
            }
            return -1;
        }
        
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            //left part is sorted
            if(nums[mid]>=nums[strt])
            {
                if(nums[mid]>=target&&target>=nums[strt])
                {
                    end=mid;
                }
                else strt=mid+1;
            }
            //right part is sorted
            else {
                    if(nums[mid]<=target&&target<=nums[end])
                    {
                        strt=mid;
                    }
                    else end=mid-1;
            }
        }
        
        if(nums[strt]==target)return strt;
        if(nums[end]==target)return end;
        return -1;
        
        
    }
};