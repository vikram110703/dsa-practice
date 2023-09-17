class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>suff(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1){
                suff[i]=prices[i];
            }
            else{
               suff[i]= max(prices[i],suff[i+1]);
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,-prices[i]+suff[i+1]);
            // cout<<suff[i]<<" ";
        }
        return ans;
    }
};