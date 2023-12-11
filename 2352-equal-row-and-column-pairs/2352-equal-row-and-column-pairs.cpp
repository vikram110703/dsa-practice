class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int>mp,mpp;
        for(int i=0;i<n;i++){
            //row
            mp[grid[i]]+=1;
        }
        for(int i=0;i<n;i++){
            vector<int>tmp;//col
            for(int j=0;j<n;j++){
                tmp.push_back(grid[j][i]);
            }
            mpp[tmp]+=1;
        }
        int ans=0;
        for(auto it:mp){
            if(mpp.count(it.first)){
                ans+=(it.second*mpp[it.first]);
            }
        }
        return ans;
        
    }
};