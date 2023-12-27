class Solution {
public:
    vector<vector<int>>dp;
    int prevTime;

    
    int cal(int i ,int prev,vector<int>&neededTime,string &colors,int prevTime){
        if(i>=neededTime.size()) return dp[i][prev]= 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int ans=INT_MAX;
        if(prev==colors[i]-'a'){
     ans=min(prevTime,neededTime[i])+cal(i+1,prev,neededTime,colors,max(prevTime,neededTime[i]));
        }
        else{
          int op3=cal(i+1,colors[i]-'a',neededTime,colors,neededTime[i]);
            ans=min(ans,op3);
        }
       return dp[i][prev]=ans;
        
    }

    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        dp.resize(n+1,vector<int>(27,-1));
        prevTime=neededTime[0];
       int ans=cal(0,26,neededTime,colors,prevTime);
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<27;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        
        return ans;
       
    }
};