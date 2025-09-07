class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long maxSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                maxSum+=nums[i];
            }
            else nums[i]=abs(nums[i]);
        }

        sort(nums.begin(),nums.end());
        vector<long long>sub;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;//min heap
        //start with min sum
        int ind=0;
        pq.push({nums[ind],ind});
        // so it is like every point we have two posibilites :
        //  1. current sub+(ind+1)
        //  2. current-last added +(ind+1) 

        k--; //we already have largest sum so we need only k-1
        while(!pq.empty() && sub.size()<k){
            pair<long long,int>ff=pq.top();
            pq.pop();
            long long curr_sub=ff.first;
            int ind=ff.second;
            sub.push_back(curr_sub);

            if(ind<nums.size()-1){
                pq.push({curr_sub+nums[ind+1],ind+1});
                pq.push({(curr_sub-nums[ind])+nums[ind+1],ind+1});
            }
        }

        //now to find k-1th largest we need to remove last value from sub
        long long sub_val=0;
        if(sub.size()>0){

           sub_val=sub.back();
        }
        return maxSum-sub_val;
    }
};