
class Solution {
public:
    bool isPossible(vector<int>&v,int mid)
    {
        // sum will handle how value is differ to mid
        long long sum=0;
        for(int i= v.size()-1;i>=0;i--)
        {
            if(v[i]>mid)
            {
                sum+=(v[i]*1ll-mid*1ll);
            }
            else
            {
                sum+=(v[i]*1ll-mid*1ll);
                if(sum<0)sum=0;
            }
        }
        return sum==0?true:false;
    }
    
    int minimizeArrayValue(vector<int>& v) {
        int n=v.size();
        int maxi=*max_element(v.begin(),v.end());
        long long ans=maxi*1ll;
        int strt=v[0],end=maxi,mid=0;
        while(end-strt>1)
        {
            mid=strt+(end-strt)/2;
            if(isPossible(v,mid))end=mid;
            else strt=mid+1;
        }
        if(isPossible(v,strt))ans=min(ans,strt*1ll);
        if(isPossible(v,end))ans=min(ans,end*1ll);
        return ans;
          
    }
};