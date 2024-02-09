class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n=nums.size();
        sort(nums.begin(),nums.end());
      
        vector<vector<int>>v;
        v.push_back({nums[0]});
        
        for(int i=1;i<n;i++){
            int ind=n,maxi=0;
           for(int j=0;j<v.size();j++){
               int val=v[j].back();
               if(nums[i]%val==0){
                   // cout<<"val "<<val<<" "<<nums[i]<<" "<<endl;
                   if(v[j].size()>maxi){
                       maxi=v[j].size();
                       ind=j;
                   }
               }
           }
            if(ind<n){
                // cout<<i<<" ";
            v.push_back(v[ind]);
            v[v.size()-1].push_back(nums[i]);
            }
            else v.push_back({nums[i]});
        }
        int maxi=0;
        int ind=0;
        for(int i=0;i<v.size();i++){
            if(v[i].size()>maxi){
                ind=i;
                maxi=v[i].size();
            }
        }
        return v[ind];
    }
};