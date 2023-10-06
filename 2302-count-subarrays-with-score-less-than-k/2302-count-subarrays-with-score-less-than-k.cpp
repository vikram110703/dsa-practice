class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
         int n = nums.size();
            long long curr = 1,ans=0;
            int j = 0;
        vector<long long >pre(n);
        for(int i=0;i<n;i++){
            if(i==0)pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
        }
            for (int i = 0; i < n; i++)
            {
               if(j==0) curr =(pre[i]*(i-j+1));
                else curr=(pre[i]-pre[j-1])*(i-j+1);
                if (curr >= k)
                {
                  	
                    while (j <= i && curr >= k)
                    {
                        // cout<<i<<" "<<j<<endl;
                        long long len = i - j;
                        ans += len;
                        j+=1;
                        if(j==0){
                            curr=(pre[i])*((i-j+1)*1ll);
                        }
                      else{
                          curr=(pre[i]-pre[j-1])*((i-j+1)*1ll);
                      }
                    }
                    if (j == i && nums[i] >= k)
                    {
                        j += 1;
                    }
                }
                 if (i == n - 1)
                {
                    // cout << j << " " << i << endl;
                    long long  len = i - j + 1;
                    ans += (len *(len + 1)) / 2;
                }
            }
            return ans;
    }
};