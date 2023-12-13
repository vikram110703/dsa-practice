class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       unordered_map<int,int>row,col;
        int n=mat.size(),m=mat[0].size();
        //row sum
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<m;j++){
                row[i]+=mat[i][j];
            }
        }
        //col sum
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                col[j]+=mat[i][j];
            }
        }
               
    int cnt=0;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(mat[i][j]==1){
                  // cout<<row[i]<<" "<<col[j]<<endl;
                  if(row[i]==1&&col[j]==1)cnt+=1;
              }
          }
      }
        return cnt;
      
    }
};