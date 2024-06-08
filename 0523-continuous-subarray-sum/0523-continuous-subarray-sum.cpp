class Solution {
public:
     
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
       
        for(int i=0;i<n;i++){
            if(i==0)nums[i]=nums[i];
            else{
                nums[i]+=nums[i-1];
            }
        }
 
        unordered_map<int,int>freq;
        freq[0]=-1;
        for(int i=0;i<n;i++){
            if(freq.count(nums[i]%k)){
                if(i-freq[nums[i]%k]>=2)return true;
            }
            else
            freq[nums[i]%k]=i;
        }
      
        return false;
        
        
        
    }
};