class Solution {
public:
    int findLucky(vector<int>& arr) {
        // unordered_map<int,int>mpp;
        vector<int>freq(501,0);
        int ans=-1;
        for(auto &it:arr){
            freq[it]++;
        }
        for(int i=500;i>=1;i--){
            if(freq[i]==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};