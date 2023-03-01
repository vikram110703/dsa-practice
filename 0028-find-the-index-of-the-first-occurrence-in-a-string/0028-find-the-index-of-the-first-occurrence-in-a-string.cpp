class Solution {
public:
    int strStr(string s, string ss) {
        int n=s.size(),m=ss.size();
        int ans=-1;
        
        for(int i=0;i<=n-m;i++)
        {
                if(s.substr(i,m)==ss)
                {
                    //store answer
                    ans=i;
                    break;
                }
        }
     return ans;   
    }
};