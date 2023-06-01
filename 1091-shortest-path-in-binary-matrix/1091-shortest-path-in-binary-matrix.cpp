class Solution {
public:
    //shortest path
    void bfs(int indx,vector<vector<int>>&adj,vector<int>&parent,unordered_map<int,bool>viss)
    {
         queue<int>q;
            q.push(indx);
            viss[indx]=true;
            while(!q.empty())
            {
               int fnode=q.front();
                q.pop();
                for(auto &child:adj[fnode])
                {
                    if(viss[child]==false)
                    {
                        parent[child]=fnode;
                        viss[child]=true;
                        q.push(child);
                    }
                }
            }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)
        {
            return -1;
        }
        vector<vector<int>>adj((n*n)+1);
        map<pair<int,int>,int>ind;
        unordered_map<int,bool>viss;
        vector<int>parent((n*n)+1,-1);
        
        int indx=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ind[{i,j}]=indx++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(i-1>=0&&grid[i-1][j]==0&&grid[i][j]==0)
               {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i-1,j}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
               }
                 if(i-1>=0&&j-1>=0&&grid[i-1][j-1]==0&&grid[i][j]==0)
               {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i-1,j-1}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
               }
                
                 if(i-1>=0&&j+1<n&&grid[i-1][j+1]==0&&grid[i][j]==0)
               {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i-1,j+1}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
               }
                
                  if(i+1<n&&j+1<n&&grid[i+1][j+1]==0&&grid[i][j]==0)
               {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i+1,j+1}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
               }
                 if(i+1<n&&grid[i+1][j]==0&&grid[i][j]==0)
               {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i+1,j}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
               }
                  if(i+1<n&&j-1>=0&&grid[i+1][j-1]==0&&grid[i][j]==0)
               {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i+1,j-1}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
               }
                
                if(j-1>=0&&grid[i][j-1]==0&&grid[i][j]==0)
                {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i,j-1}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
                }
                if(j+1<n&&grid[i][j+1]==0&&grid[i][j]==0)
                {
                    int indx1=ind[{i,j}];
                   int  indx2=ind[{i,j+1}];
                   adj[indx1].push_back(indx2);
                   adj[indx2].push_back(indx1);
                }
                
                
            }
        }
        
        //shortest path frm 1 to n*n;
        int indxx=1;
        bfs(indxx,adj,parent,viss);
        int cnt=1;
        int lastInd=n*n;
        while(parent[lastInd]!=-1)
        {
            cnt+=1;
            lastInd=parent[lastInd];
        }
        if(lastInd!=1)return -1;
        else
        return cnt;
      
        
        
    }
};