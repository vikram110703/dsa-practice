class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
         int n=nums.size();
            map<int,int>mpp;
        int ans=0;
        int strt=-1;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
            while(mpp[nums[i]]>k){
                strt+=1;
                mpp[nums[strt]]-=1;
                
            }
            ans=max(ans,i-strt);
        }
        return ans;
    }
};