class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=k&&mpp[nums[i]]>0){
                if(mpp[k-nums[i]]>0){
                    if(nums[i]==k-nums[i]){
                        if(mpp[nums[i]]>1){
                             ans+=1;
                    mpp[nums[i]]-=1;
                    mpp[k-nums[i]]-=1;
                        }
                    }
                    else {
                         ans+=1;
                    mpp[nums[i]]-=1;
                    mpp[k-nums[i]]-=1;
                    }
                   
                }
            }
        }
        return ans;
    }
};