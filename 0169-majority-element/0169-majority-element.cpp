class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0,curr=1,ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(curr>cnt){
                    cnt=curr;ans=nums[i-1];
                }
                curr=1;
            }
            else curr+=1;
        }
        if(curr>cnt)ans=nums[n-1];
        return ans;
        
    }
};