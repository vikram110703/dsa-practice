class Solution
{
    public:
        int equalPairs(vector<vector < int>> &grid)
        {
            map<vector < int>, vector< int>> row, col;
            int n = grid.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    tmp.push_back(grid[i][j]);
                }
                row[tmp].push_back(i);
                tmp.clear();
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    tmp.push_back(grid[j][i]);
                }
                col[tmp].push_back(i);
                tmp.clear();
            }
            
            tmp.clear();
            int cnt=0;
            for(auto &it:row)
            {
                tmp=it.first;
                if(col.find(tmp)!=col.end())
                {
                    cnt+=(it.second.size()*col[tmp].size());
                }
            }
            return cnt;
            
        }
};