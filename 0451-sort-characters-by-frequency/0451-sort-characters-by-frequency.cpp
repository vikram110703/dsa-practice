class Solution {
public:
   static bool cmp(const pair<char,int>&a,const pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        int n=s.size();
        vector<pair<char,int>>vp;
        map<char,int>v;
        for(int i=0;i<n;i++){
             v[s[i]]+=1;
        }
        for(auto &it:v){
            vp.push_back({it.first,it.second});
        }
        sort(vp.begin(),vp.end(),cmp);
        char a;
        int val;
        string ans="";
        for(int i=0;i<vp.size();i++){
            a=vp[i].first;
            val=vp[i].second;
            while(val>0){
                ans+=a;
                val-=1;
            }
        }
        return ans;
    }
};