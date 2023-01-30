class Solution {
public:
    int chk(int n)
    {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        return chk(n-1)+chk(n-2)+chk(n-3);
    }
    int tribonacci(int n) {
        
        // return chk(n);
        int ans=0;
        if(n==1)ans=1;
        if(n==2)ans=1;
        int a,b,c;
        a=0,b=1,c=1;
        for(int i=3;i<=n;i++)
        {
            ans=a+b+c;
            // int tmp=ans;
            a=b;
            b=c;
            c=ans;
            
        }
        return ans;
        
    }
};