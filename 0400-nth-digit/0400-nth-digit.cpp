class Solution {
public:
    int findNthDigit(int x) {
        long long n=x*1ll;
       long long  strt=90,digit=2;
        if(n<=9)return n;
        n-=9;
        while(n>strt){
            // cout<<strt<<" "<<digit<<" "<<n<<endl;
            if(n<=digit*strt)break;
            n-=(digit*strt);
            digit+=1;
            strt*=10;
        }
        // cout<<strt<<" "<<digit<<" "<<n<<endl;
        int req=(n+digit-1)/digit;
        // cout<<"d-> "<<req<<endl;
        int rem=(n+digit-1)%digit;
        int ans=pow(10,digit-1);
       
        ans+=req-1;
         // cout<<"ans-> "<<ans<<endl;
        string s=to_string(ans);
        // cout<<s[rem]<<endl;
        return s[rem]-'0';
    }
};