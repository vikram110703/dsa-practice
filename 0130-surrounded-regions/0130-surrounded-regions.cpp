class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n=board.size(),m=board[0].size();        
        vector<vector<bool>>viss(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0||j==0||i==n-1||j==m-1)
               {
                   if(board[i][j]=='O')
                   {
                       q.push({i,j});
                       viss[i][j]=true;
                   }
               }
           }
       }
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0&&board[i-1][j]=='O'&&viss[i-1][j]==false)
            {
                viss[i-1][j]=true;
                q.push({i-1,j});
            }
             if(i+1<n&&board[i+1][j]=='O'&&viss[i+1][j]==false)
            {
                viss[i+1][j]=true;
                q.push({i+1,j});
            }
             if(j-1>=0&&board[i][j-1]=='O'&&viss[i][j-1]==false)
            {
                viss[i][j-1]=true;
                q.push({i,j-1});
            }
              if(j+1<m&&board[i][j+1]=='O'&&viss[i][j+1]==false)
            {
                viss[i][j+1]=true;
                q.push({i,j+1});
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O'&&viss[i][j]==false)board[i][j]='X';
            }
        }
        
        
    }
};