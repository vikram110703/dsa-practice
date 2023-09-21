class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>pre(n),suff(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            pre[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            suff[i]=sum;
        }
        map<int,int>mpp,mp;
        for(int i=0;i<n;i++)
        {
            mpp[suff[i]]=i;
            mp[pre[i]]=i;
        }
        int mini=INT_MAX;
        
// .............. cout<<pre[i]<<" "<<rem<<" "<<mpp[rem]<<endl;

        for(int i=0;i<n;i++)
        {
            int rem=x-pre[i];
            if(rem==0)
            {
                mini=min(mini,i+1);
                continue;
            }
            if(mpp.count(rem))
            {
                if(mpp[rem]>i){
                int cnt=n-(mpp[rem]-i-1);
                mini=min(mini,cnt);
                }
            }
        } 
// ................. treaversal from end..............
        
         for(int i=n-1;i>=0;i--)
        {
            int rem=x-suff[i];
            if(rem==0)
            {
                mini=min(mini,n-i);
                continue;
            }
            if(mp.count(rem))
            {
                // cout<<pre[i]<<" "<<rem<<" "<<mp[rem]<<endl;
                if(mp[rem]<i){
                int cnt=n-(i-mp[rem]-1);
                mini=min(mini,cnt);
                }
            }
        }
        
        if(mini==INT_MAX)return -1;
        else return mini;
    }
};