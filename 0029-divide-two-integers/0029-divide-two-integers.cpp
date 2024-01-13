class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=min(dividend*1ll/divisor*1ll,INT_MAX*1ll);
        if(ans<0)return max(INT_MIN*1ll,ans);
        return ans;
    }
};