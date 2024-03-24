class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       int strt=1,end=n;
        while(end-strt>1){
            int mid=strt+(end-strt)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid)cnt+=1;
            }
            if(cnt>mid){end=mid;}
            else strt=mid+1;
            
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=strt)cnt+=1;
        }
        if(cnt>strt)return strt;
        else return end;
        
    }
};