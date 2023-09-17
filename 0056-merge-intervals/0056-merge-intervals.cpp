class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        set<pair<int,int>>st;
        int n=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(st.empty()){
                st.insert({v[i][1],v[i][0]});
            }
            else{
                auto it=st.lower_bound({v[i][0],0});
                if(it!=st.end())//mil gaya
                {
                    pair<int,int>p=*it;
                    if(v[i][1]>p.first)p.first=v[i][1];
                    st.erase(it);
                    st.insert(p);
                }
                else st.insert({v[i][1],v[i][0]});
            }
        }
        vector<vector<int>>ans;
        for(auto &it:st){
            ans.push_back({it.second,it.first});
        }
        return ans;
    }
};