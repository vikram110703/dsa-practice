class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
       int i=0,j=0;
        while(i<n&&j<n){
            if(nums[j]!=0&&nums[i]==0){
             swap(nums[i],nums[j]);
                i+=1;j+=1;
            }
            else if(nums[i]==0&&nums[j]==0){
                j+=1;
            }
            else if(nums[i]!=0&&nums[j]!=0){
                i+=1;j+=1;
            }
            else i+=1;
        }
        
    }
};