class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>mp,mpp;
        for(int i=0;i<word1.size();i++)mp[word1[i]]++;
        for(int i=0;i<word2.size();i++)mpp[word2[i]]++;
        if(mp.size()!=mpp.size())return false;
        multiset<int>st;
        for(auto &it:mp)st.insert(it.second);
        for(auto it:mpp){
            // there should not be a uniqe element 
            if(mp.count(it.first)==false)return false;
            if(st.find(it.second)==st.end())return false;
            else{
                st.erase(st.find(it.second));
            }
        }
            return true;
        
    }
};