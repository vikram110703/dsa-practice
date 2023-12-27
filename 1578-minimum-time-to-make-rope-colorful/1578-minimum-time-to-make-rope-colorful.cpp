class Solution {
public:
    int ans=0,currSum=0,maxi=0;
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        char prev=colors[0];
        for(int i=0;i<n;i++){
            currSum=0;maxi=neededTime[i];
            while(i<n&&colors[i]==prev){
                currSum+=neededTime[i];
                maxi=max(maxi,neededTime[i]);
                i+=1;
            }
           ans+=currSum-maxi;
            if(i<n){
                prev=colors[i];
                i-=1;
            }
        }
       return ans;
    }
};