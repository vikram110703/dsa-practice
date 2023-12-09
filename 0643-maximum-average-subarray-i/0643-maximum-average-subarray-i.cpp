class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum=0.0,maxAvg=0;
        for(int i=0;i<k;i++){
            currSum+=double(nums[i]*1.0);
        }
        maxAvg=currSum/(k*1.0);
        for(int i=k;i<nums.size();i++){
            currSum+=double(nums[i]*1.0);
            currSum-=double(nums[i-k]*1.0);
            maxAvg=max(maxAvg,currSum/(k*1.0));
        }
        return maxAvg;
        
    }
};