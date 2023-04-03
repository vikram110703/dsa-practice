class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        
        int ans=0,i=0,j=v.size()-1;
        sort(v.begin(),v.end());
        while(i<=j)
        {
            if(v[i]+v[j]<=limit)++i,--j;
            
            else --j;
            
            
            ++ans;
        }
        return ans;
        
    }
};