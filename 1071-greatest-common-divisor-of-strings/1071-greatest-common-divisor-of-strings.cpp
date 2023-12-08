class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
     int n=str1.size(),m=str2.size();
        int gcd=__gcd(n,m);
        string subString=str1.substr(0,gcd);
        for(int i=0;i<n;i+=gcd){
            if(str1.substr(i,gcd)!=subString)return "";
        }
        for(int i=0;i<m;i+=gcd){
            if(str2.substr(i,gcd)!=subString)return "";
        }
        return subString ;
        
    }
};