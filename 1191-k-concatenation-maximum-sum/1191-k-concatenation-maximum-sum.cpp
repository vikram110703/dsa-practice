class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long cur = 0 , maxSub = 0 , pre = 0, maxPre = 0 , suff = 0 , maxSuff = 0, n = arr.size() , mod = 1e9+7;
        
        for(int i = 0 ;i<n;i++){
            cur+=arr[i];
            maxSub= max(maxSub, cur);
            cur = max(cur,0ll);
            
            pre+=arr[i];
            maxPre = max(pre,maxPre);
            
            suff+=arr[n-1-i];
            maxSuff = max(maxSuff,suff);
        }
        
        return k==1 ? maxSub : max({0ll, maxSub, maxPre + maxSuff + (k-2)*max(0ll,pre) }) % mod;
        
    }
};