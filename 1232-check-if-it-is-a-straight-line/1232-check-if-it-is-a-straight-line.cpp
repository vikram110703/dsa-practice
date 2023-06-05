class Solution
{
    public:
        bool checkStraightLine(vector<vector < int>> &coordinates)
        {
            int n = coordinates.size();
            bool chk = true;
            for (int i = 1; i < n - 1; i++)
            {
                int x1, x2, x3, y1, y2, y3;
                x1 = coordinates[i - 1][0], x2 = coordinates[i][0], x3 = coordinates[i + 1][0];
                y1 = coordinates[i - 1][1], y2 = coordinates[i][1], y3 = coordinates[i + 1][1];
                double m1, m2;
                int d1, d2;
                d1 = x3 - x2;
                d2 = x2 - x1;
                if (d1 == 0)
                    m1 = x3;
                else
                    m1 = (y3 - y2) *1.0 / d1 * 1.0;
                if (d2 == 0) m2=x2;
                else 
                m2 = (y2 - y1) *1.0 / d2 * 1.0;
                if (m1 != m2)
                {
                    chk = false;
                    break;
                }
            }
            return chk;
        }
};