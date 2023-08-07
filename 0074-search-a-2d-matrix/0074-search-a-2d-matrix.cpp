class Solution
{
    public:

        void search(vector<vector < int>> &matrix, int &strt, int &end, int mid, int ind,int target)
        {
            while (end - strt > 1)
            {
                mid = strt + (end - strt) / 2;
                if (matrix[ind][mid] > target)
                {
                    end = mid - 1;
                }
                else	//<=target
                {
                    strt = mid;
                }
            }
        }

    bool searchMatrix(vector<vector < int>> &matrix, int target)
    {
        int n=matrix.size(), m = matrix[0].size();
        int strt = 0, end = n - 1, mid;
       	// find the row
        while (end - strt > 1)
        {
            mid = strt + (end - strt) / 2;
            if (matrix[mid][0] > target)
            {
                end = mid - 1;
            }
            else	//<=target
            {
                strt = mid;
            }
        }
       	// chk for the row
        if (matrix[strt][0] <= target && matrix[strt][m - 1] >= target)
        {
            // cout<<strt<<endl;
            int ind = strt;
            strt = 0, end = m - 1, mid = 0;
            search(matrix, strt, end, mid, ind,target);
           	// chk in the column
            if (matrix[ind][strt] == target) return true;
            if (matrix[ind][end] == target) return true;
            return false;
        }
        else if (matrix[end][0] <= target && matrix[end][m - 1] >= target)
        {
            // cout<<end<<endl;
            int ind = end;
            strt = 0, end = m - 1, mid = 0;
            search(matrix, strt, end, mid, ind,target);
           	// chk in the column
            if (matrix[ind][strt] == target) return true;
            if (matrix[ind][end] == target) return true;
            return false;
        }
        else return false;
    }
};