class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long t) {
        
        int n=s.size();
        int m=p.size();;
        sort(p.begin(),p.end());
        // multiset<long long>st;
        // for(int i=0;i<m;i++)
        // {
        //     st.insert(p[i]*1ll);
        // }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            long long  req=(t/s[i]*1ll);
            if(t%(s[i]*1ll)==0){;;}
            else req+=1;
            auto it=lower_bound(p.begin(),p.end(),req);
            int total=distance(it,p.end());
            ans.push_back(total);
        }
        return ans;
    }
};