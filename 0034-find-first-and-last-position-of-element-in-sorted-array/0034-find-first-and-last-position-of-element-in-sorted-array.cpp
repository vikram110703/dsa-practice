class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int strt=0,end=n-1,mid=strt+(end-strt)/2;
        if(n==0)return {-1,-1};
        
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            if(nums[mid]>=target)
            {
                end=mid;
            }
            //<target
            else {
                strt=mid+1;
            }
        }
        // not found
        if(nums[strt]!=target&&nums[end]!=target)
        {
            return {-1,-1};
        }
        vector<int>ans;
        if(nums[strt]==target)ans.push_back(strt);
        else ans.push_back(end);
        
        strt=0,end=n-1;
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            if(nums[mid]<=target)strt=mid;
            //>target
            else end=mid-1;
        }
        if(nums[end]==target)ans.push_back(end);
        else ans.push_back(strt);
        
        return ans;
        
    }
};