class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int maxi=0;
        for(int i=1;i<n;i++){
            int diff=points[i][0]-points[i-1][0];
           maxi=max(maxi,diff); 
        }
        return maxi;
        
    }
};