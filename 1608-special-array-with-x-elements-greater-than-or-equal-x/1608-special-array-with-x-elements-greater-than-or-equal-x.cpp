class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>=ans){
                if(i>0){
                    if(nums[i-1]<ans)return ans;
                }
                else return ans;
            }
            ans+=1;
        }
        return -1;
    }
};