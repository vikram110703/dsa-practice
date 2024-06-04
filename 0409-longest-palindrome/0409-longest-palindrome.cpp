class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        map<char,int>mpp;
        int isOdd=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]+=1;
        }
        int ans=0;
        for(auto &it:mpp){
            if((it.second)%2)isOdd=1;
            ans+=(it.second)/2;
        }
        return (2*ans)+isOdd;
    }
};