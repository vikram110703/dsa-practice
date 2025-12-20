class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        int n=nums.size();
        if(n<=0)return 0;
        while(i<j){
            while(i<j && nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            i++;
        }
        i=0;
        while(i<n){
            if(nums[i]==val){
                return i;
            }
            i+=1;
        }
        return n;
        
    }
};