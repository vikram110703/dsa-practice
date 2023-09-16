class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int strt=0,mid=0,end=n-1;
        // three pointer 
        while(end-mid>=0)
        {
            if(nums[mid]==0){
                swap(nums[strt],nums[mid]);
                strt+=1;mid+=1;
            }
            else if(nums[mid]==1)
            {
                mid+=1;
            }
            else //nums[mid]==2
            {
                swap(nums[mid],nums[end]);
                end-=1;
            }
        }
        
    }
};