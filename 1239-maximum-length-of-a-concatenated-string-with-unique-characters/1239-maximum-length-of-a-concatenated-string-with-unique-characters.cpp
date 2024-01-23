class Solution {
public:
    vector<int>dp;
    int n;
    // int maxLen=0;
    // map<char,int>mpp;
    
     int cal(int i,vector<string>&arr,int maxLen,map<char,int>&mpp){
         if(i==n){
             return maxLen;
         }
       //  if(dp[i]!=-1)return dp[i];
         string s=arr[i];
         bool chk=true;
         for(int j=0;j<s.size();j++){
             mpp[s[j]]++;
             if(mpp[s[j]]>1){
                 chk=false;
             }
         }
         int take=0,notTake=0;
         
         if(chk){
             take=cal(i+1,arr,maxLen+s.size(),mpp);
            
         }
              for(int j=0;j<s.size();j++){
                 mpp[s[j]]--;
             }
             notTake=cal(i+1,arr,maxLen,mpp);
         
         return dp[i]=max(take,notTake);
     }
    
    int maxLength(vector<string>& arr) {
        n=arr.size();
        dp.resize(n+1,-1);
        map<char,int>mpp;
        int ans= cal(0,arr,0,mpp);
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        return ans;
    }
};