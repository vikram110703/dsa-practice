class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        int n=v.size();
        sort(v.begin(),v.end());
        int minDiff=INT_MAX;
        int a=0,ans=t;
        
        int strt,end,mid;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               a=v[i]+v[j];
                auto it=lower_bound(v.begin()+j+1,v.end(),t-a)-v.begin();
                if(it!=n)
                {
                    int currSum=a+(v[it]);
                    minDiff=min(minDiff,abs(t-currSum));
                    if(minDiff==abs(t-currSum))
                    {
                        ans=currSum;
                    }
                }
                if(it!=0)
                {
                    if(it!=j+1)
                    {
                        --it;
                       int currSum=a+(v[it]);
                        minDiff=min(minDiff,abs(t-currSum));
                        if(minDiff==abs(t-currSum))
                    {
                        ans=currSum;
                    }
                    }
                }
                
                
            }
        }
        return ans;
        
    }
};