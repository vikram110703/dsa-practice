class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            auto it=st.find(i);
            if(it==st.end())ans.push_back(i);
        }
        return ans;
        
    }
};