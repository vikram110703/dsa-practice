class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        //cyclic sort
        while(i<n){
            if(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else i+=1;
        }
        for(int i=0;i<n;i++)if(nums[i]!=i+1)return i+1;
        return n+1;
        
    }
};