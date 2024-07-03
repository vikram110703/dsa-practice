class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxDiff=nums[n-1]-nums[0];
        int removed=0;
        if(n<=4){
            return 0;
        }
        for(int i=0;i<=3;i++){
            int diff=abs(nums[n-4+i]-nums[i]);
            maxDiff=min(maxDiff,diff);
        }
        return maxDiff;
        
    }
};