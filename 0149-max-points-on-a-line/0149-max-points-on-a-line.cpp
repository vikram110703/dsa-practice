class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(); 
            int maxi=0;
        
        for(int i=0;i<n;i++){
            unordered_map<double,int>slopes;
            int inf=0;//slope=infinity

            for(int j=i+1;j<n;j++){
                double dx=points[i][0]*1.0-points[j][0]*1.0;
                double dy=points[i][1]*1.0-points[j][1]*1.0;
                if(dx==0)inf+=1;
                else{
                    double slope=(dy*1.0)/(dx*1.0);
                    if(dy==0)slopes[0.0]+=1;
                    else
                    slopes[slope]+=1;
                }
            }
            
              for(auto &it:slopes)
              {
                 if(it.second>=maxi){
                  maxi=it.second;
                 // cout<<it.first<<endl;
                 }
              }
                maxi=max(maxi,inf);
        }
   
        return maxi+1;
    }
};