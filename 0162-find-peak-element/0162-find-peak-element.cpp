class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int strt=0,end=n-1;
        int mid=strt+(end-strt)/2;
        while(end-strt>1){
            mid=strt+(end-strt)/2;
            int md=nums[mid];
            if(mid==0){
                if(md>nums[mid+1])return mid;
                else strt=mid+1;
            }
            else if(mid==n-1){
                if(md>nums[mid-1])return mid;
                else end=mid-1;
            }
            else{
                if(md>nums[mid-1]&&md>nums[mid+1])return mid;
                else if(nums[mid-1]>md)end=mid-1;
                else strt=mid;
            }
        }
        if(nums[strt]>nums[end])return strt;
        else return end;
        
    }
};