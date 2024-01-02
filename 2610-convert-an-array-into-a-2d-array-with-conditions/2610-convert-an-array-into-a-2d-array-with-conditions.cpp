class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int maxFreq=0;
        for(auto &it:nums)
        {
            mpp[it]+=1;maxFreq=max(maxFreq,mpp[it]);
        }
        vector<vector<int>>ans(maxFreq);
        int i=0;
        while(i<maxFreq){
            for(auto &it:mpp){
                if(it.second>0){
                ans[i].push_back(it.first);
                mpp[it.first]-=1;
                }
                
            }i+=1;
        }
        return ans;
    }
};