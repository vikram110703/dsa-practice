class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int ind=abs(nums[i])-1;
            if(nums[ind]<0)ans.push_back(ind+1);
            else {
                nums[ind]=-1*nums[ind];
            }
            
        }
        
        return ans;
    }
};