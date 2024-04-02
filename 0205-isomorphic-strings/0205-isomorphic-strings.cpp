class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char>mpp;
        for(int i=0;i<n;i++){
            if(mpp.count(s[i])==false){
                mpp[s[i]]=t[i];
            }
            else{
                // cout<<"-> "<<s[i]<<" "<<mpp[s[i]]<<endl;
                if(t[i]!=mpp[s[i]])return false;
            }
        }
        set<char>st;
        for(auto it:mpp){
            if(st.size()==0)st.insert(it.second);
            else{
                int sz=st.size();
                st.insert(it.second);
                if(st.size()==sz)return false;
            }
        }
        return true;
    }
};