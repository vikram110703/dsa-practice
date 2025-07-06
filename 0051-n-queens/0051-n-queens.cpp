class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>tmp(n,string(n,'.'));
        
        solve(n,ans,tmp,0);
        return ans;

    }

    void solve(int n,vector<vector<string>>&ans,vector<string>&tmp,int col)
    {
        if(col==n){ //valid 
            ans.push_back(tmp);
            return;
        }

        for(int row=0;row<n;row++){
            if(check(tmp,row,col)){
                tmp[row][col]='Q';
                solve(n,ans,tmp,col+1);
                tmp[row][col]='.';
            }
        }
    }

     bool check(vector<string>& tmp, int row, int col){
        int n = tmp.size(); 
        
        // check horizontally for queens in same row
        for(int x = 1; x <= col; x++){
            if(tmp[row][col-x] == 'Q') return false;
        }
        
        // check diagonals
        for(int x = 1; row-x >= 0 && col-x >= 0; x++){
            if(tmp[row-x][col-x] == 'Q') return false;
        }

        for(int x = 1; row+x < n && col-x >= 0; x++){
            if(tmp[row+x][col-x] == 'Q') return false;
        } 
        
        return true;
    }
};