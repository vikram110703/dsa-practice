class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        vector<int>vv;
        for(auto it:st)vv.push_back(it);
        // sort(nums.begin(),nums.end());
        n=vv.size();
        int ans=0;
        int curr=0;
        
   // [1,2,0,1]-> 0 1 1 2 
        
        for(int i=1;i<n;i++)
        {
            curr=0;
            while(i<n&&vv[i]-vv[i-1]==1)
            {
                i+=1;curr+=1;
            }
            //
            if(curr>0)curr+=1;
           ans=max({ans,curr,1});
            
            
        }
        return max(ans,1);
        
    }
};