class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mpp;
        vector<vector<int>>ans(2);
        for(int i=0;i<matches.size();i++){
            int a=matches[i][0];
            int b=matches[i][1];
            mpp[b]++;
        }
        for(auto &it:mpp){
            if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
         for(int i=0;i<matches.size();i++){
            int a=matches[i][0];
            if(mpp[a]==0){
                ans[0].push_back(a);
                mpp[a]=1;
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        // sort(ans.begin(),ans.end());
        return ans;
        
    }
};