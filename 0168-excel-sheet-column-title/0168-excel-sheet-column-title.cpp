class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
       while(columnNumber){
           columnNumber-=1;
           s+=('A'+(columnNumber%26)) ;
           columnNumber/=26;
       }
        reverse(s.begin(),s.end());
        return s;
        
    }
};