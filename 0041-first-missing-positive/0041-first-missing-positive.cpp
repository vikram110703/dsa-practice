class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //CYCLIC SORT
         // int i=0;
        // while(i<n){
        //     if(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]){
        //         swap(nums[i],nums[nums[i]-1]);
        //     }
        //     else i+=1;
        // }
        // for(int i=0;i<n;i++)if(nums[i]!=i+1)return i+1;
        // return n+1;
        
        bool chk=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1)chk=true;
            if(nums[i]<=0||nums[i]>n)nums[i]=1;
        }
        if(!chk)return 1;
        // cout<<nums[0]<<endl;
        for(int i=0;i<n;i++){
            int ind=abs(nums[i])-1;
            if(nums[ind]>0)nums[ind]*=-1;
        }
        for(int i=0;i<n;i++)if(nums[i]>0)return i+1;
        return n+1;
    }
};