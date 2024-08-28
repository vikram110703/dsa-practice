class Solution {
public:

    int n,m;
    vector<vector<bool>>viss;

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        n=grid1.size();
        m=grid1[0].size();

        viss.resize(n+1,vector<bool>(m+1,false));
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(viss[i][j]==false && grid2[i][j]==1)
                {
                    bool isPresent=false;//if zero present in path (grid1)
                    dfs(i,j,isPresent,grid1,grid2);
                    if(isPresent==false)ans+=1;
                }
            }
        }

        return ans;
    }

    void dfs(int i,int j,bool &isPresent,vector<vector<int>>&grid1,vector<vector<int>>&grid2)
    {
        viss[i][j]=true;
        if(grid1[i][j]==0)isPresent=true;

        vector<int> dirx={1,-1,0,0};
        vector<int> diry={0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int dx=i+dirx[k];
            int dy=j+diry[k];
            if(dx>=0 && dx<n && dy>=0 && dy<m)//valid cell
            {
                if(grid2[dx][dy]==1 && viss[dx][dy]==false)//valid cell condition
                dfs(dx,dy,isPresent,grid1,grid2);
            }
        }
    }
};
