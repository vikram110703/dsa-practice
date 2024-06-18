class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>diff;
        int n=difficulty.size();
        for(int i=0;i<n;i++){
            diff.push_back({difficulty[i],profit[i]});
        }
        int ans=0;
        sort(diff.begin(),diff.end());
        vector<int>maxProfit(n);
        for(int i=0;i<n;i++){
            if(i==0){
                maxProfit[i]=diff[i].second;
            }
            else{
                maxProfit[i]=max(maxProfit[i-1],diff[i].second);
            }
        }
        for(int i=0;i<worker.size();i++){
            int cap=worker[i];//capacity of worker 
            pair<int,int>p={cap,maxProfit[n-1]};
            auto it=upper_bound(diff.begin(),diff.end(),p)-diff.begin();
            // cout<<it<<" ";
                it--;
            if(it>=0){
                ans+=maxProfit[it];
                // cout<<maxProfit[it]<<endl;
            }
            
        }
        return ans;
    }
};