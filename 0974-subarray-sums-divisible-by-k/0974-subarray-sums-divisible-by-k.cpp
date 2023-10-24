class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         int n=nums.size();
       // prefix sum
        for(int i=1;i<n;i++){
              nums[i]+=nums[i-1];
        }
 
        unordered_map<int,int>freq;
        freq[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            // nums[i]%k-> (nums[i]%k+k)%k , to handle negative modulo 
           count+=freq[(nums[i]%k+k)%k];
            freq[(nums[i]%k+k)%k]+=1;
        }
      
        return count;
    }
};