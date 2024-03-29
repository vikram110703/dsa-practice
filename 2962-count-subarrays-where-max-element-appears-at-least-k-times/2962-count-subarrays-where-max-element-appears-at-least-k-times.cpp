class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int>v;
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)v.push_back(i);
        }
        
        long long ans=0,last_ind=0;
        for(int i=k-1;i<v.size();i++){
            
            int left=v[last_ind]+1;
            if(i!=k-1){
                left=v[last_ind]-v[last_ind-1];
            }
            long long right=nums.size()-v[i];
            ans+=left*right;
            last_ind+=1;
            
        }
        return ans;
        
    }
};