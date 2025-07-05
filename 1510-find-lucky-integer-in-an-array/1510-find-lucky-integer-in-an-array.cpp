class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int ans=-1;
        for(auto &it:arr){
            mpp[it]++;
        }
        for(auto &it:mpp){
            if((it.first==it.second) && it.first> ans)ans=it.first;
        }
        return ans;
    }
};