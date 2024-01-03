class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')cnt+=1;
            }
            if(cnt>0)v.push_back(cnt);
        }
        int ans=0;
        if(v.size()==0)return ans;
        for(int i=0;i<v.size()-1;i++){
            ans+=(v[i]*v[i+1]);
        }
        return ans;
    }
};