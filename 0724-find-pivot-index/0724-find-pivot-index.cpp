class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
            int right=(nums[n-1]-nums[i]);
            int left=0;
            if(i!=0)left=nums[i-1];
            if(left==right)return i;
        }
        return -1;
    }
};