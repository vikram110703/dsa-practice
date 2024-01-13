class Solution {
public:
    int minSteps(string s, string t) {
        multiset<int>st;
        for(int i=0;i<t.size();i++)st.insert(s[i]);
        for(int i=0;i<t.size();i++){
            auto it=st.lower_bound(t[i]);
            if(*it==t[i])st.erase(it);
        }
        return st.size();
    }
};