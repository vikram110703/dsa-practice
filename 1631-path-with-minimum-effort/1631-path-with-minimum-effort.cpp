class Solution {
public:
    int n;
    int m;
    void bfs(int ii,int jj,vector<vector<int>>&heights,vector<vector<int>>&dist){
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{ii,jj}});
        dist[ii][jj]=0;
        while(!q.empty()){
            int currDist=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            // cout<<ii<<" "<<jj<<" "<<dist[ii][jj]<<endl;
            q.pop();
            if(currDist>dist[i][j])continue;
            if(i+1<n){
                int ChildDist=dist[i+1][j];
                int diff=abs(heights[i][j]-heights[i+1][j]);
                int maxi=max(diff,currDist);
                if(dist[i+1][j]>maxi){
                    dist[i+1][j]=maxi;
                    q.push({maxi,{i+1,j}});
                }
            }
            if(i-1>=0){
                int ChildDist=dist[i-1][j];
                int diff=abs(heights[i][j]-heights[i-1][j]);
                int maxi=max(diff,currDist);
                if(dist[i-1][j]>maxi){
                    dist[i-1][j]=maxi;
                    q.push({maxi,{i-1,j}});
                }
            }
            if(j+1<m){
                int ChildDist=dist[i][j+1];
                int diff=abs(heights[i][j]-heights[i][j+1]);
                int maxi=max(diff,currDist);
                if(dist[i][j+1]>maxi){
                    dist[i][j+1]=maxi;
                    q.push({maxi,{i,j+1}});
                }
            }
            if(j-1>=0){
                int ChildDist=dist[i][j-1];
                int diff=abs(heights[i][j]-heights[i][j-1]);
                int maxi=max(diff,currDist);
                if(dist[i][j-1]>maxi){
                    dist[i][j-1]=maxi;
                    q.push({maxi,{i,j-1}});
            }
        }
    }
}
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        bfs(0,0,heights,dist);

        return dist[n-1][m-1];
    }
};