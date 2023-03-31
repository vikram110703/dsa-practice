class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       int n=nums.size();
       // swap method-> swap (nums[i],nums[nums[i]-1]) untill its not it's right position 
        
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)ans.push_back(i+1);
        }
        return ans;
    }
};