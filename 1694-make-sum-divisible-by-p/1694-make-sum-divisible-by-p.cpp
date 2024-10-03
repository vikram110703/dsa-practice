class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<int,int>mpp;// [sum]->ind ;
        long total=0;
        for(int i=0;i<n;i++)
        {
            nums[i]%=p;
            total+=nums[i];
        }
        long req=total%p;
        if(req==0)return 0;

        long curr_sum=0;
        mpp[0]=-1;

        int ans=n;
        for(int i=0;i<n;i++)
        {
            curr_sum+=nums[i];
            int modVal=curr_sum%p;
            mpp[modVal]=i;
            int tmp=(modVal-req+p)%p;// add +p so that negative value can be handled
            
            if(mpp.count(tmp))
            {
                ans=min(ans,i-mpp[tmp]);
            }
        }

        return ans==n?-1:ans;        
    }
};

// pLogN