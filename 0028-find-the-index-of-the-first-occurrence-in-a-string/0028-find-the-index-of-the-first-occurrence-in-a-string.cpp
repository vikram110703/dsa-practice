class Solution {
public:
    int strStr(string s, string ss) {
        int ans=-1;
        
        auto it=s.find(ss);
        if(it!=s.size())ans=it;
     
     return ans;   
    }
};