class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)freq[nums[i]]+=1;
        int ans=0;
        for(auto &it:freq){
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second>1)
            {
                if(it.second%3==0)ans+=(it.second)/3;
                else
                ans+=((it.second)/3)+1;
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};