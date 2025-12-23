class Solution {
public:
    int findRow(int start,int end,vector<vector<int>>& matrix, int target){
        int m=matrix[0].size();
        while(end-start>1){
            int mid=start+(end-start)/2;
            if(matrix[mid][m-1]>=target){
                end=mid;
            }
            else start=mid+1;
        }
        return matrix[start][m-1]>=target?start:end;
    }

    bool findValue(int row,int start,int end,vector<vector<int>>& matrix, int target){
        while(end-start>1){
            int mid=start+(end-start)/2;
            if(matrix[row][mid]>=target){
                end=mid;
            }
            else start=mid+1;
        }
        if(matrix[row][start]==target)return true;
        if(matrix[row][end]==target)return true;
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();

        int row=findRow(0,n-1,matrix,target);
        return findValue(row,0,m-1,matrix,target);
    }
};