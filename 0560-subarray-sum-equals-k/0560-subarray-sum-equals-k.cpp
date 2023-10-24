class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        // prefix sum
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int count=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i]-k)){
                // cout<<i<<" ";
                count+=mpp[nums[i]-k];
            }
           mpp[nums[i]]+=1;
        }
        return count;
    }
};