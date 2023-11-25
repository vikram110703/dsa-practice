class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int suffSum=0;
        int preSum=0;
        
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            suffSum=totalSum-preSum;
            int res=0;
            res=suffSum-(nums[i]*(n-i-1));
            res+=((nums[i]*i)-(preSum-nums[i]));
            nums[i]=res;
        }
        return nums;
    }
};