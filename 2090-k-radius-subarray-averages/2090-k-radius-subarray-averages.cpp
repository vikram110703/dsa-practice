class Solution
{
    public:
        vector<int> getAverages(vector<int> &nums, int k)
        {
            int n = nums.size();
           	long long sum=0;
            int j=0,jj=0;
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
                
                if(i>=2*k)
                {
                    jj=i;
                    break;
                }
               
            }
            jj+=1;
            vector<int>ans(n,-1);
            for(int i=k;i<n;i++)
            {
                if(i+k>=n)break;
                ans[i]=sum/(2*k+1);
                sum-=nums[j++];
                if(jj<=n-1)sum+=nums[jj++];
                
            }
           
            return ans;
        }
};