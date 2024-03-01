class Solution {
public:
   // static bool cmp(const char &a,const char &b){
   //      return a<b;
   //  }
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                swap(s[i],s[s.size()-1]);break;
            }
        }
        
        return s;
        
    }
};