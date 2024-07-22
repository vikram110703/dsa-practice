class Solution {
public:
    int n;
    int m;
    void bfs(int ii,int jj,vector<vector<int>>&heights,vector<vector<int>>&dist){
        queue<pair<int,int>>q;
        q.push({ii,jj});
        dist[ii][jj]=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            // cout<<ii<<" "<<jj<<" "<<dist[ii][jj]<<endl;
            q.pop();
            if(i+1<n){
                int ChildDist=dist[i+1][j];
                int currDist=dist[i][j];
                int diff=abs(heights[i][j]-heights[i+1][j]);
                int maxi=max(diff,currDist);
                if(dist[i+1][j]>maxi){
                    dist[i+1][j]=maxi;
                    q.push({i+1,j});
                }
            }
            if(i-1>=0){
                int ChildDist=dist[i-1][j];
                int currDist=dist[i][j];
                int diff=abs(heights[i][j]-heights[i-1][j]);
                int maxi=max(diff,currDist);
                if(dist[i-1][j]>maxi){
                    dist[i-1][j]=maxi;
                    q.push({i-1,j});
                }
            }
            if(j+1<m){
                int ChildDist=dist[i][j+1];
                int currDist=dist[i][j];
                int diff=abs(heights[i][j]-heights[i][j+1]);
                int maxi=max(diff,currDist);
                if(dist[i][j+1]>maxi){
                    dist[i][j+1]=maxi;
                    q.push({i,j+1});
                }
            }
            if(j-1>=0){
                int ChildDist=dist[i][j-1];
                int currDist=dist[i][j];
                int diff=abs(heights[i][j]-heights[i][j-1]);
                int maxi=max(diff,currDist);
                if(dist[i][j-1]>maxi){
                    dist[i][j-1]=maxi;
                    q.push({i,j-1});
            }
        }
    }
}
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        bfs(0,0,heights,dist);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dist[i][j]<<" ";
        //     }cout<<endl;
        // }
        return dist[n-1][m-1];
    }
};