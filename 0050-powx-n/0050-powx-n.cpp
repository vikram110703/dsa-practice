class Solution {
public:
    
     // (Binary Exponentiation)
    double myPow(double x, int n) {
        if(n>0)
        {
            if(n==1)return x;
            double ans=myPow(x,n/2);
            if(n%2==0)
            {
                return ans*=ans;
            }
            else return(ans*ans*x); 
        }
        else if(n<0)
        {
            if(n==-1)return 1/x;
            double ans=myPow(x,n/2);
            if(n%2==0)
            {
                return ans*ans;
            }
            else return ans*ans*(1/x);
        }
        return 1;
        
    }
};