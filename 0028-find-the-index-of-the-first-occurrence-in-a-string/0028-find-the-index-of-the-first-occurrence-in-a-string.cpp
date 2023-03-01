class Solution {
public:
    int strStr(string &s, string &ss) {
        
        auto it=s.find(ss);
        if(it!=s.size())return it;
     
     return -1;   
    }
};