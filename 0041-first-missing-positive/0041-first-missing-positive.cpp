class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            while(v[i]<=n&&v[i]>0&&v[i]!=v[v[i]-1])
            {
                swap(v[i],v[v[i]-1]);
            }
            
        }
        int ans=n+1;
        for(int i=0;i<n;i++)
        {
            if(v[i]!=i+1)
            {
                ans=i+1;break;
            }
        }
        return ans;
        
    }
};