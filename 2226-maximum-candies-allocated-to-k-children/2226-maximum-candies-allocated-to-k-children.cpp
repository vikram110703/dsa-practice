class Solution {
public:
    int maximumCandies(vector<int>& v, long long k) {
        sort(v.begin(),v.end());
        int n=v.size();
        long long strt=0,end=v[n-1];
        long long mid;
        //candi== count of people to distribute mid no of candies to per person
        long long candi=0;
        // if((v[0]*1ll)*n<k)return 0;
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            candi=0;
            
            for(int i=0;i<n;i++)
            {
                candi+=((v[i]*1ll)/mid);
            }
            candi=(candi*1ll);
            if(candi<k)
            {
                // reduce candies per person
                end=mid-1;
                
           }
            else 
            {
                strt=mid;
            }
            
        }
        candi=0;
        if(end>0)
        {
        for(int i=0;i<n;i++)
        {
            candi+=((v[i]*1ll)/end);
        }
        
        candi=candi*1ll;
        if(candi>=k)return end;
        else return strt;
        }
        else if(strt>0)
        {
              for(int i=0;i<n;i++)
        {
            candi+=((v[i]*1ll)/strt);
        }
        
        candi=candi*1ll;
        if(candi>=k)return strt;
        else return end;
        }
        return 0;
        
    }
};