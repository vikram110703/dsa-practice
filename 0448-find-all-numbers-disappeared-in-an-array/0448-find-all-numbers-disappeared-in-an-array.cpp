class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       int n=nums.size();
        unordered_map<int,bool>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]=true;
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            if(mpp[i]==false)ans.push_back(i);
        }
        return ans;
        
    }
};