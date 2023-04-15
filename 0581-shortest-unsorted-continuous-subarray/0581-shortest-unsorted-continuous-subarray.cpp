class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        // we will store index in stack 
        stack<int>st;
        int left=n,right=0;
        for(int i=0;i<n;i++)
        {
            while(st.size()!=0&&nums[st.top()]>nums[i])
            {
                left=min(left,st.top());
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
         for(int i=nums.size()-1;i>=0;i--)
        {
            while(st.size()!=0&&nums[st.top()]<nums[i])
            {
                right=max(right,st.top());
                st.pop();
            }
            st.push(i);
        }
        return right-left+1>0?right-left+1:0;
    }
};