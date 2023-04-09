class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       int n = nums.size(),m;
        map<int,vector<int>>mpp;
        vector<long long>pre(n),ans(n);
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]].push_back(i);
          
        }
        vector<int>tmp;
        
        for(auto it:mpp)
        {
            tmp=it.second;m=tmp.size();
            if(m==1)ans[tmp[0]]=0;
            else
            {
                for(int i=0;i<m;i++)
                {
                      if(i==0)pre[i]=tmp[i];
                      else pre[i]=pre[i-1]+tmp[i];
                }
                for(int i=0;i<m;i++)
                {
                    long long aa=((i*1ll)*(tmp[i])*1ll);
                    if(i!=0)aa-=(pre[i-1]);
                    aa+=((pre[m-1]-pre[i])-((1ll*(m-1-i))*(tmp[i]*1ll)));
                    ans[tmp[i]]=aa;
                }
                pre.clear();
            }
            
        }
        return ans;
        
    }
};