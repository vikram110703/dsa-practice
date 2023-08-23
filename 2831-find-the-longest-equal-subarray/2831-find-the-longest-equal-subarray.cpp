class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> mpp(n + 1);
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]].push_back(i);
        }

        int maxi = 0;
        for (int jj = 0; jj < mpp.size(); jj++)
        {
            int i=0;
            
           for(int j=0;j<mpp[jj].size();j++)
           {
                if(mpp[jj][j]-mpp[jj][i]-(j-i)<=k){
                    maxi=max(maxi,j-i+1);
                }else{
                    while((mpp[jj][j]-mpp[jj][i]-(j-i)>k))i+=1;
                }
           }
        }
        
        return maxi;
    }
};