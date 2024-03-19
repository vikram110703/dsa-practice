class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        int cnt=1;
       int  mini=points[0][1];
            for(int i=1;i<n;i++){
               int l=points[i][0];
                int h=points[i][1];
                if(mini>=l){
                    mini=min(mini,h);
                }
                else{
                     cnt+=1;
                    mini=h;
                }
                
            }
        return cnt;
        
    }
};