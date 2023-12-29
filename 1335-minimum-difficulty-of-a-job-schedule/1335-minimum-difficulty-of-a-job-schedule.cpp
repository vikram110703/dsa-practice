class Solution {
public:
    vector<vector<int>>dp;
    int n;
    
    int cal(int i,int d,vector<int>&diff){
        //base case 
        if(i>=n){
            if(d==0)return 0;
            else return 100000;
        }
        //i<n&&d<=0 
        if(d<=0)return 1e5;
        
        if(dp[i][d]!=-1)return dp[i][d];
        int ans=INT_MAX,maxi=INT_MIN;
        for(int ind=i;ind<n;ind++){
            maxi=max(maxi,diff[ind]);
            int tmp=maxi+cal(ind+1,d-1,diff);
            ans=min(ans,tmp);
        }
        return dp[i][d]=ans;
    }
    
    int minDifficulty(vector<int>& diff, int d) {
        n=diff.size();
        dp.resize(n+1,vector<int>(d+1,-1));
       int ans=cal(0,d,diff);
        return ans>=1e5?-1:ans;
        
    }
};