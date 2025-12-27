class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int sum=0;
        for(auto &it:nums){
            mpp[it]++;
            sum+=it;
        }

        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            //assume this is outlier
            int outlier=nums[i];
            int currSum=sum-nums[i];

            //it should be even
            if((currSum %2 )!=0)continue;
            int specialNum=currSum/2;
            if(outlier==specialNum && mpp[outlier]>=2){
                ans=max(ans,outlier);
            }
            if(outlier!=specialNum && mpp[specialNum]>=1){
                ans=max(ans,outlier);
            }
        }
        return ans;
    }
};