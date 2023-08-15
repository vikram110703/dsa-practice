class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int>st;
        // priority_queue<int>pq;
        int maxi=INT_MIN;
        if(n==1)
        {
            return {nums[0]};
        }
        if(k==1)
        {
            return nums;
        }
        for(int i=0;i<k;i++)
        {
           st.insert(nums[i]);
            maxi=max(maxi,nums[i]);
        }
        vector<int>ans;
        ans.push_back(maxi);
        int strt=0;
        for(int i=k;i<n;i++)
        {
            int old=nums[strt];
            int neww=nums[i];
            
            auto it=st.lower_bound(old);
            st.erase(it);
            auto itt=st.end();
            itt--;
                int curMax=*itt;
            if(neww>=curMax){
                maxi=neww;
            }
            else{
                maxi=curMax;
            }
            st.insert(neww);
            ans.push_back(maxi);
            strt+=1;
        }
        return ans;
    }
};