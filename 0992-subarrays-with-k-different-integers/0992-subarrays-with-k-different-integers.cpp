class Solution {
public:
    // subarray with atmost k different integers
    int subArray(vector<int>&nums,int k){
        map<int,int>mpp;
        int ans=0,left=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
            while(mpp.size()>k){
                mpp[nums[left]]-=1;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left+=1;
            }
            ans+=i-left+1; 
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return (subArray(nums,k)- subArray(nums,k-1));
       
    }
};