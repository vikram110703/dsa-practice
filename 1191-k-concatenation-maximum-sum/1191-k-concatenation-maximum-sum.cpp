class Solution
{
    public:
        int mod = 1e9 + 7;
    
    int kadan(vector<int>arr){
         long long maxi = 0, curr = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            curr = (curr + arr[i]) % mod;
            maxi = max(maxi, curr);
            if (curr <= 0)
            {
                curr = 0;
            }
        }
        return maxi%mod;
    } 
    
    
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        long long maxiii;
        maxiii= kadan(arr);
            
        if (k == 1)
        {
            return maxiii;
        }
        // if(k==2){
        //     for(int i=0;i<n;i++)arr.push_back(arr[i]);
        //     return kadan(arr);
        // }
        long long pre=0,suff=0,cur=0,curr=0;
        for(int i=0;i<n;i++){
            cur+=arr[i];
            pre=max(pre,cur);
            curr+=arr[n-1-i];
            suff=max(suff,curr);
        }
         cout<<pre<<" "<<suff<<" "<<maxiii<<" "<<cur<<endl;
        long long  total=pre+suff+(k-2)*cur;
        return max({maxiii,0ll,total,(pre+suff)})%mod;
       
    }
};




// [-5,-2,0,0,3,9,-2,-5,4,-5,-2,0,0,3,9,-2,-5,4]

