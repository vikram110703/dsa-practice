class Solution {
public:
    int cal(int strt,int end,string&s,vector<vector<int>>&dp){
            int n=s.size();
            if(end<strt||strt>=n||end<0||strt<0||end>=n)return 0;
        if(dp[strt][end]!=-1)return dp[strt][end];
        if(strt==end)return dp[strt][end]=1;
        if(s[strt]!=s[end])return dp[strt][end]=0;
        else{
            //s[strt]==s[end]
            if(end-strt==1)return dp[strt][end]=1;
            bool isPal=cal(strt+1,end-1,s,dp);
            return dp[strt][end]=isPal;
        }
        
        
    }
    
    //this is memoization version     
    
    string longestPalindrome(string s) {
        int n=s.size();
        // int maxLen=1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string palindrome;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ans=cal(i,j,s,dp);
                if(ans==1)
                {
                    if(palindrome.size()<j-i+1)palindrome=s.substr(i,j-i+1);
                }
                // if(ans==1)cout<<i<<" "<<j<<endl;
            }
        }
        return palindrome;
    }
};