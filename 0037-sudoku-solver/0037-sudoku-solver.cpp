class Solution {
public:
    bool isValid(int i, int j, int num, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == num ||board[k][j]==num) return false;
        }


        // check for valid subset
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for (int row = startRow; row < startRow + 3; row++) {
            for (int col = startCol; col < startCol + 3; col++) {
                if (board[row][col] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if(board[row][col]!='.')continue;
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(row,col,num, board)) {
                        board[row][col]=num;
                        if(solve(board))return true;

                        // backtrack becaues it will not solve suduku
                        board[row][col]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool chk=solve(board);
    }
};