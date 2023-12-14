class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int,int>oneRow,oneCol;
        int n=grid.size(),m=grid[0].size();
        //row
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                oneRow[i]+=(grid[i][j]==1);
            }
        }
        //col
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                oneCol[j]+=(grid[i][j]==1);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int zRow=m-oneRow[i];
                int zCol=n-oneCol[j];
                grid[i][j]=(oneRow[i]+oneCol[j])-(zRow+zCol);
            }
        }
        return grid;
        
    }
};