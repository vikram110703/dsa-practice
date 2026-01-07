class Solution {
public:

//time O(m X n)
//space O(m X n)
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        int area = 0;

        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();
            area += 1;

            for (auto& it : dir) {
                int xx = f.first + it.first;
                int yy = f.second + it.second;

                if (xx >= 0 && xx < grid.size() && yy >= 0 &&
                    yy < grid[0].size() && grid[xx][yy] == 1) {
                    q.push({xx, yy});
                    grid[xx][yy] = 0;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    maxi = max(maxi, bfs(i, j, grid));
                }
            }
        }
        return maxi;
    }
};