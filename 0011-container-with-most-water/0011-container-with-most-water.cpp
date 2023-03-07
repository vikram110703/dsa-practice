class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        // vector<pair<int,int>>v;
        // for(int i=0;i<n;i++)
        // {
        //     v.push_back({h[i],i});
        // }
        // sort(v.begin(),v.end());
        
        
        int i=0,j=n-1;
        int maxi=0,a,b;
        while(i<j)
        {
            a=min(h[i],h[j]);
            b=j-i;
            maxi=max(a*b,maxi);
            if(h[i]>h[j])
            {
                j-=1;
            }
            else
            {
                i+=1;
            }
        }
        return maxi;
        
        
        
    }
};