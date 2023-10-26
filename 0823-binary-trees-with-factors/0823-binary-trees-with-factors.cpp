class Solution {
public:
    int mod=1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,long long>mpp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)mpp[arr[i]]++;
        // calculation for every element 
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int req=arr[i]/arr[j];
                    if(mpp[req]>0){
                        mpp[arr[i]]+=(mpp[arr[j]]*mpp[req]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(mpp[arr[i]]))%mod;
        }
        return ans;
    }
};