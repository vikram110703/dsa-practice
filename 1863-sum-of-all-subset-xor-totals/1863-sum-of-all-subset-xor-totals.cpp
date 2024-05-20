class Solution {
public:
        int chk(int ind,int currXor,vector<int>&nums){
            int n=nums.size();
            if(ind==n)return currXor;
            return chk(ind+1,currXor^nums[ind],nums)+chk(ind+1,currXor,nums);
            
        }
    
    int subsetXORSum(vector<int>& nums) {
        return chk(0,0,nums);
        
    }
};