class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<int>>minDist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    minDist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(i-1>=0&&minDist[i-1][j]==-1)
            {
                minDist[i-1][j]=minDist[i][j]+1;
                q.push({i-1,j});
            }
             if(i+1<n&&minDist[i+1][j]==-1)
            {
                minDist[i+1][j]=minDist[i][j]+1;
                  q.push({i+1,j});
            }
             if(j-1>=0&&minDist[i][j-1]==-1)
            {
                minDist[i][j-1]=minDist[i][j]+1;
                  q.push({i,j-1});
            }
             if(j+1<m&&minDist[i][j+1]==-1)
            {
                minDist[i][j+1]=minDist[i][j]+1;
                  q.push({i,j+1});
            }
            
        }
        
        return minDist;
    }
};