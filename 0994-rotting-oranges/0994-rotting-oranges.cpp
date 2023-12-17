class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
       queue<pair<int,int>>q;
        map<pair<int,int>,bool>viss;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                viss[{i,j}]=false;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz>0){
                sz-=1;
            int i=q.front().first;
            int j=q.front().second;
                // cout<<i<<" "<<j<<endl;
            viss[{i,j}]=true;
            q.pop();
            if(i+1<n&&viss[{i+1,j}]==false)if(grid[i+1][j]==1)
            {q.push({i+1,j});  viss[{i+1,j}]=true;
            }
            if(i-1>=0&&viss[{i-1,j}]==false)if(grid[i-1][j]==1){
                q.push({i-1,j});viss[{i-1,j}]=true;
            }
            if(j+1<m&&viss[{i,j+1}]==false)if(grid[i][j+1]==1)
            {q.push({i,j+1}); viss[{i,j+1}]=true;
            }
            if(j-1>=0&&viss[{i,j-1}]==false)if(grid[i][j-1]==1)
            {q.push({i,j-1}); viss[{i,j-1}]=true;
            }
        }
          if(q.size()>0)time+=1;
            // cout<<endl;
        }
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&viss[{i,j}]==false){
                    return -1;
                }
            }
        }
        return time;
        
    }
};