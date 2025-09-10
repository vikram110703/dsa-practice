class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j]='0';
        while (!q.empty()) {
            pair<int, int> loc=q.front();
            q.pop();
            for(auto &it:dir) {
                int xx = loc.first + it.first;
                int yy = loc.second + it.second;
                if (xx < grid.size() && xx >= 0 && yy >= 0 &&
                    yy < grid[0].size() && grid[xx][yy] == '1') {
                    q.push({xx, yy});
                    grid[xx][yy]='0';// mark visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans += 1;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};