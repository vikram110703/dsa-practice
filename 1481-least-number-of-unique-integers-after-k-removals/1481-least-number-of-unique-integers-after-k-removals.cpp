class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++)mpp[arr[i]]++;
        vector<int>v;
        for(auto it:mpp){
            v.push_back(it.second);
}
        sort(v.begin(),v.end());
        
        for(int i=0;;i++){
            // cout<<v[i]<<" "<<k<<endl;
            if(v[i]<=k)
            {   
                k-=v[i];v[i]=0;
            }
            else{
                v[i]-=k;k=0;
            }
            if(k==0){
              return v[i]>0 ? v.size()-i: v.size()-1-i;
            }
        }
        return 0;
    }
};