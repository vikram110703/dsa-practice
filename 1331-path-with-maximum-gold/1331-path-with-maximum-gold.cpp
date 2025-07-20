class Solution {
public:

    int calculate(int i,int j,vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size()||i<0||j<0)
        {
            return 0;
        }
        
        if(grid[i][j]==0){
            return 0;
        }

        int left=0,right=0,up=0,down=0;
        if(grid[i][j]==0)return 0;

        int tmp=grid[i][j];
        grid[i][j]=0;//so that couldn't visit this cell again

        left=tmp+calculate(i-1,j,grid);
        right=tmp+calculate(i+1,j,grid);
        up=tmp+calculate(i,j-1,grid);
        down=tmp+calculate(i,j+1,grid);

        // cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;

        grid[i][j]=tmp; //backtrack

        return max({left,right,up,down});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0)
                maxi=max(maxi,calculate(i,j,grid));
            }
        }
        return maxi;
    }
};