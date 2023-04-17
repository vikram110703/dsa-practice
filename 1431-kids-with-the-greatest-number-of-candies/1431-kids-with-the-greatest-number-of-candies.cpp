class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n=candies.size(),maxi=*max_element(candies.begin(),candies.end());
        vector<bool>ans(n);
        for(int i=0;i<n;i++)
        {
            candies[i]+extra>=maxi?ans[i]=true:ans[i]=false;
        }
        return ans;
    }
};