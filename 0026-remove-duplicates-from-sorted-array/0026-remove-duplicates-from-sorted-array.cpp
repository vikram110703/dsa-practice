class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ind=1;
        for(int i=1;i<n;i++){
            int currElem=nums[i];
            //valid
            if(currElem != nums[ind-1]){
                nums[ind]=currElem;
                ind++;
            }
        }
        return ind;
    }
};