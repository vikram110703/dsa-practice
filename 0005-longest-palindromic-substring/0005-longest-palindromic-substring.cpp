class Solution
{
    public:
        string longestPalindrome(string s)
        {

            int n = s.size();
            int arr[n][n];
            int maxi = 1, strtIndx = 0, endIndx = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    arr[i][j] = 0;
                    if (i == j) arr[i][j] = 1;
                    if (j - i == 1)
                    {
                        if (s[i] == s[j])
                        {
                            arr[i][j] = 2;
                            maxi = 2;
                            strtIndx = i, endIndx = j;
                        }
                    }
                }
            }

            for (int gap = 2; gap < n; gap++)
            {
                for (int i = 0; i < n; i++)
                {
                    int j = i + gap;
                    if (j >= n) break;
                    if (arr[i + 1][j - 1] > 0 && (s[i] == s[j]))
                    {
                        arr[i][j] = gap;
                        maxi = max(maxi, arr[i][j]);
                        if (maxi == arr[i][j])
                        {
                            strtIndx = i, endIndx = j;
                        }
                    }
                    else
                    {
                        arr[i][j] = 0;
                    }
                }
            }

            return s.substr(strtIndx, endIndx - strtIndx + 1);
        }
};