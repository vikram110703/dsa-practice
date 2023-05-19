class Solution
{
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {
            queue<pair<int, int>> q;
            int n = image.size(), m = image[0].size();
            int currCol = image[sr][sc];
            q.push({ sr,
                sc });
            vector<vector<bool>>viss(n,vector<bool>(m,false));
            while (!q.empty())
            {
                int i = q.front().first;
                int j = q.front().second;
                image[i][j]=color;
                viss[i][j]=true;
                q.pop();

                if (i - 1 >= 0 && image[i - 1][j] == currCol && viss[i - 1][j] == false)
                {
                    viss[i - 1][j] = true;
                    q.push({ i - 1,
                        j });
                    image[i - 1][j] = color;
                }
                if (i + 1 < n && image[i + 1][j] == currCol && viss[i + 1][j] == false)
                {
                    viss[i + 1][j] = true;
                    q.push({ i + 1,
                        j });
                    image[i + 1][j] = color;
                }
                if (j - 1 >= 0 && image[i][j - 1] == currCol && viss[i][j - 1] == false)
                {
                    viss[i][j - 1] = true;
                    q.push({ i,
                        j - 1 });
                    image[i][j - 1] = color;
                }
                if (j + 1<m&& image[i][j + 1] == currCol && viss[i][j + 1] == false)
                {
                    viss[i][j + 1] = true;
                    q.push({ i,
                        j + 1 });
                    image[i][j + 1] = color;
                }
            }
            return image;
        }
};