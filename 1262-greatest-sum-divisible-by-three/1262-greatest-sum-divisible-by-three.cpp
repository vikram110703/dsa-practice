class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,pair<int,int>>mpp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)if(nums[i]%3!=0)mpp[nums[i]%3]={-1,-1};
        int totalSum=0,curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]%3==0) totalSum+=nums[i];
            else {
                curr+=nums[i];
                    int rem=nums[i]%3;
                    // // cout<<nums[i]<<" "<<rem<<" "<<i<<endl;
                    if(mpp[rem].first==-1)mpp[rem].first=i;
                    else if(mpp[rem].second==-1)mpp[rem].second=i;
                
            }
        }

        int extraRem=curr%3;
        // cout<<extraRem<<endl;
        if(extraRem==0)totalSum+=curr;
        else{
           int a=curr;
            if(extraRem==1){
                if(mpp.count(1)&&mpp[1].first!=-1){
                    a=min(a,nums[mpp[1].first]);
                }
                if(mpp.count(2)&& mpp[2].second!=-1){
                    int sum=nums[mpp[2].first]+nums[mpp[2].second];
                    a=min(a,sum);
                }
                curr-=a;
            }
            else{
                if(mpp.count(2)&&mpp[2].first!=-1){
                    a=min(a,nums[mpp[2].first]);
                    // cout<<mpp[2].first<<" "<<mpp[2].second<<endl;
                }
                if(mpp.count(1)&&mpp[1].second!=-1){
                    int sum=nums[mpp[1].first]+nums[mpp[1].second];
                    a=min(a,sum);
                }
                curr-=a;
            }
            totalSum+=curr;
            
        }
        return totalSum;
        
    }
};