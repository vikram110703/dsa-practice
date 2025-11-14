class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        vector<int>leftOne(n+1,0);

        for(int i=0;i<n;i++){
            leftOne[i+1]=leftOne[i];
            if(s[i]=='1')leftOne[i+1]+=1;
        }
        int oneCount=leftOne[n];
        int zeroCount=n-oneCount;

        //only two pattern : 010  101 
        long long ways=0;
        for(int i=1;i<n-1;i++){
            if(s[i]=='1'){
                // 010
                int leftZero=(i+1)-leftOne[i+1];
                int rightOne=oneCount-leftOne[i+1];
                int rightZero=(n-(i+1))-(rightOne);
                ways+=((1LL*leftZero)*(rightZero*1ll));
            }
            else{
                // 101
                int rightOne=oneCount-leftOne[i+1];
                ways+=((leftOne[i]*1LL)*(rightOne*1ll));
            }
        }
        return ways;
    }
};