class Solution {
public:
    
    void merze(vector<int>&nums,int strt,int mid,int end){
        vector<int>left;
        vector<int>right;
        for(int i=strt;i<=mid;i++){
            left.push_back(nums[i]);
        }
        for(int i=mid+1;i<=end;i++){
            right.push_back(nums[i]);
        }
        
        int i=0,j=0,leftSize=left.size(),rightSize=right.size();
        int curr=strt;//starting index merzed array
        while(i<leftSize&&j<rightSize){
            if(left[i]<=right[j]){
                nums[curr]=left[i];
                i+=1;
            }
            else if(right[j]<left[i]){
                nums[curr]=right[j];
                    j+=1;
            }
            curr+=1;
        }
        while(i<leftSize){
            nums[curr]=left[i];
            i+=1;curr+=1;
        }
        while(j<rightSize){
            nums[curr]=right[j];
            j+=1;curr+=1;
        }
        left.clear();
        right.clear();
    }
    
    
    void merzeSort(vector<int>&nums,int strt,int end){
        if(strt>=end)return;
        int mid=strt+(end-strt)/2;
        merzeSort(nums,strt,mid);
        merzeSort(nums,mid+1,end);
        merze(nums,strt,mid,end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
       merzeSort(nums,0,nums.size()-1);
        return nums;
    }
};