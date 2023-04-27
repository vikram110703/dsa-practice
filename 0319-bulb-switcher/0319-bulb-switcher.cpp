class Solution {
public:
    int bulbSwitch(int n) {
        // understand the pattern... 1 to n perfect sqr numnerd bulbs 'll remain on 
        int a,ans=0;
        for(int i=1;i<=sqrt(n);i++)
        {
            a=i*i;
            if(a<=n)ans+=1;
        }
        return ans;
        
    }
};