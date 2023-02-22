class Solution {
public:
    int shipWithinDays(vector<int>& v, int d) {
        int n=v.size();
        int strt=0,end=0;
        for(int i=0;i<n;i++)
        {
                strt=max(strt,v[i]);
            end+=v[i];
        }
        
        int mid,ans=end;
        while(strt<end)
        {
            mid=strt+(end-strt)/2;
            int dd=0;
            int cap=0;
            for(int i=0;i<n;i++)
            {
                if(v[i]+cap<=mid)
                {
                    cap+=v[i];
                }
                else
                {
                    dd+=1;cap=v[i];
                }
            }
            // cout<<"dd "<<dd<<endl;
            // cout<<"mid "<<mid<<endl;
            if(dd+1<=d)
            {
                ans=min(mid,ans);
                end=mid;
            }
            else
            {
                strt=mid+1;
            }
        }
        return ans;
    }
};