class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int n=v.size();
        int strt=0,end=n-1,mid=strt+(end-strt)/2;
        int ans=-1;
        if(n==0)return 0;        
        while(strt<end)
        {
            mid=strt+(end-strt)/2;
            if(v[mid]==t)
            {
                ans=mid;
                return mid;
                break;
            }
           
            if(v[mid]>t)end=mid;
           else  if(v[mid]<t)strt=mid+1;
            
        }
        return v[strt]>=t?strt:strt+1;
        
        
    }
};