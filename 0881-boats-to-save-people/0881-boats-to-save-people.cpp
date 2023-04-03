class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        int n=v.size();
        int ans=0;
        int j=n-1;
        int i=0;
        sort(v.begin(),v.end());
        while(i<=j)
        {
            if(v[i]+v[j]<=limit)
            {
                ans+=1;i+=1;j-=1;
            }
            else
            {
                ans+=1;
                j-=1;
            }
        }
        return ans;
        
    }
};