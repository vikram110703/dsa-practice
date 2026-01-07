class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0,prev2=0;
        // prev1,prev2
        for(int i=0;i<n;i++){
            int op1=prev2+nums[i];
            int op2=prev1;
            int currMax=max(op1,op2);
            prev2=prev1;
            prev1=currMax;
        }
        return prev1;
    }
};