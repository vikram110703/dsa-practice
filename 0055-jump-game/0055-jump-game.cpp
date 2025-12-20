class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        bool isPossible=false;
        int currMax=0;
        int i=0;
        while(i<n){
            currMax=max(currMax,nums[i]);
            if(currMax>0){
            currMax--;
            i++;
            }
            else break;
        }
       return i>=n-1;
    }
};