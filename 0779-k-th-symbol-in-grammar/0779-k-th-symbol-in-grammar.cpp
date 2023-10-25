class Solution {
public:
    char cal(int n,int k)
    {
        if(n==1){
            return '0';
        }
        int total=pow(2,n-1);
        if(k>total/2){
            char ans=cal(n-1,k-(total/2));
            if(ans=='0')ans='1';
            else ans='0';
            // // cout<<n<<" "<<k<<" "<<ans<<endl;
            return ans;
        }
        else{
             char ans=cal(n-1,k);
            // cout<<n<<" "<<k<<" "<<ans<<endl;
            return ans;
        }
    }
    int kthGrammar(int n, int k) {
        int ans=cal(n,k)-'0';
        return ans;
    }
};