class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &mat)
        {
            int n = mat.size(), m = mat[0].size();

            vector<int> ans;
            int rowstrt = 0, rowend = n - 1, colend = m - 1, colstrt = 0;
            while (rowstrt <= rowend && colstrt <= colend)
            {
               
                
                for (int j = colstrt; j <= colend; j++)
                {
                    ans.push_back(mat[rowstrt][j]);
                }
                ++rowstrt;

                for (int i = rowstrt; i <= rowend; i++)
                {
                    ans.push_back(mat[i][colend]);
                }
                --colend;
                if (rowstrt > rowend || colstrt > colend) break;  
                for (int j = colend; j >= colstrt; j--)
                {
                    ans.push_back(mat[rowend][j]);
                }
                --rowend;
                for (int i = rowend; i >= rowstrt; i--)
                {
                    ans.push_back(mat[i][colstrt]);
                }
                ++colstrt;
                
                // cout << rowstrt << " " << rowend << " "<<colstrt << " " << colend << endl;
            }
            return ans;
        }
};