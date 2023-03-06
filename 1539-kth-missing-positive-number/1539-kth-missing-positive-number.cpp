class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int n = arr.size();
            int strt = arr[0] - 1;
            if (k >= strt)
            {
                k -= strt;
            }
            else
            {
                return k;
            }
            if (k == 0) return strt;
            int missing;
            for (int i = 0; i < n - 1; i++)
            {
                missing = arr[i];
                if (arr[i + 1] - missing > 1)
                {
                    missing+=1;
                    while(missing<arr[i+1])
                    {
                        k-=1;
                        // cout << missing << " ";
                        if (k == 0)
                        {
                            return missing;
                        }
                        missing += 1;
                    }

                    // while (arr[i + 1] - missing >= 1)
                    // {
                    //     cout << arr[i] << " ";
                    //     if (k == 0)
                    //     {
                    //         return missing;
                    //     }
                    //     missing += 1;
                    //     k -= 1;
                    // }
                }
            }
            int last = arr[n - 1] + (k);
            return last;
        }
};