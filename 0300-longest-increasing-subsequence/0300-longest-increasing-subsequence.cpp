class Solution {
public:
    int dpSolution(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n,1);
        // dp[i] :LIS ending at index i 
        //nums[i] will be maximum till index i
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               if(nums[j]<nums[i]){
                   dp[i]=max(dp[i],dp[j]+1);
               } 
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
    int binarySearchSol(vector<int>&nums){
        int n=nums.size();
        vector<int>substr;
        for(int i=0;i<n;i++){
            if((substr.size()==0)||(nums[i]>substr[substr.size()-1])){
                substr.push_back(nums[i]);
            }
            else{
             // nums[i]<last   //find index of element >=nums[i];
                int index=lower_bound(substr.begin(),substr.end(),nums[i])-substr.begin();
                substr[index]=nums[i];
            }
        }
        return substr.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans=dpSolution(nums);
        int ans2=binarySearchSol(nums);
        return ans2;
    }
};