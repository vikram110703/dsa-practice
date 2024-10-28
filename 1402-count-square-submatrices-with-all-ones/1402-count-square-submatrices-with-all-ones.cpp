class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)continue;
                // [i][j] -> is right bottom coloum of squre
                if(j-1>=0 && i-1>=0)
                {
                    matrix[i][j]=1+min({matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1]});
                }

                ans+=matrix[i][j];
            }
        }

        return ans;
    }
};