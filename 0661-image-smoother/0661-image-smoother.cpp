class Solution
{
    public:
        vector<vector < int>> imageSmoother(vector<vector < int>> &img)
        {
            int n = img.size(), m = img[0].size();
            vector<vector<int>>ans(n,vector<int>(m,0));
            int availCell = 0, sum = 0;
            for (int i = 0; i < n; i++)
            {
                
                for (int j = 0; j < m; j++)
                {
                    availCell=0,sum=0;
                    sum += img[i][j];
                    availCell += 1;//curr element
                    if (i - 1 >= 0)
                    {
                        sum += img[i - 1][j];
                        availCell += 1;
                    }
                     if (i - 1 >= 0&&j-1>=0)
                    {
                        sum += img[i - 1][j-1];
                        availCell += 1;
                    }
                     if (i + 1 < n)
                    {
                        sum += img[i + 1][j];
                        availCell += 1;
                    }
                     if (i + 1 < n&&j+1<m)
                    {
                        sum += img[i + 1][j+1];
                        availCell += 1;
                    }
                    if(j-1>=0)
                    {
                        sum+=img[i][j-1];
                        availCell+=1;
                    }
                     if(j-1>=0&&i+1<n)
                    {
                        sum+=img[i+1][j-1];
                        availCell+=1;
                    }
                      if(j+1<m)
                    {
                        sum+=img[i][j+1];
                        availCell+=1;
                    }
                      if(j+1<m&&i-1>=0)
                    {
                        sum+=img[i-1][j+1];
                        availCell+=1;
                    }
      
                    int avg=floor(sum/availCell);
                    ans[i][j]=avg;
                    
                }
            }
            return ans;
        }
};