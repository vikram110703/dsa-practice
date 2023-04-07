class Solution
{
    public:
        void chk(vector<vector < int>> &grid,queue<pair<int,int>>&q)
        {
            int m=grid[0].size();
            // queue<pair<int, int>> q;
            // q.push({ i,
            //     j });
            
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(grid[x][y]==0)continue;
                grid[x][y] = 0;

                if (x + 1 < grid.size() && grid[x + 1][y] == 1) q.push({ x + 1,
                    y });
                if (y + 1 < m && grid[x][y + 1] == 1) q.push({ x,
                    y + 1 });
                if (x - 1 >= 0 && grid[x - 1][y] == 1) q.push({ x - 1,
                    y });
                if (y - 1 >= 0 && grid[x][y - 1] == 1) q.push({ x,
                    y - 1 });
            }
        }

    int numEnclaves(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m=grid[0].size();
        int sum = 0;queue<pair<int,int>>q;
       	// queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            
            if (grid[i][0] == 1)
            {
                // chk(grid,i, 0);
                q.push({i,0});
            }
        }
        chk(grid,q);
        for (int i = 0; i < n; i++)
        {
           
            if (grid[i][m - 1] == 1)
            {
                // chk(grid, i, m - 1);
                q.push({i,m-1});
            }
        }
        chk(grid,q);
        for (int i = 0; i < m; i++)
        {
           
            if (grid[0][i] == 1)
            {
                // chk(grid, 0, i);
                q.push({0,i});
            }
        }
        chk(grid,q);
        for (int i = 0; i < m; i++)
        {
            
            if (grid[n-1][i] == 1)
            {
                // chk(grid, n - 1, i);
                q.push({n-1,i});
            }
        }
        chk(grid,q);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1) sum += 1;
                // cout<<grid[i][j]<<" ";
            }
        }
        return sum;
    }
};