class Solution {
public:
    const int  maxm= 5*10000;
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        
        int n=f.size(),m=p.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int a=f[i][0],b=f[i][1];
            mpp[a]++;
            mpp[b+1]--;
        }
        mpp[0]=0;
        int prevSum=0;
        for(auto &it:mpp){
            it.second+=prevSum;
            prevSum=it.second;
        }
        vector<int>ans(m,0);
        for(int i=0;i<m;i++)
        {
            auto it=mpp.upper_bound(p[i]);
            it--;
            ans[i]=it->second;
        }
        return ans;
        
    }
};