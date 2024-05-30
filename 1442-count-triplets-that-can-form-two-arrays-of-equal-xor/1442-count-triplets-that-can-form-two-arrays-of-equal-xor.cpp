class Solution
{
    public:
        int countTriplets(vector<int> &arr)
        {
            int n = arr.size();
            vector<int> pre(n);
            pre[0] = arr[0];
            for (int i = 1; i < n; i++)
            {
                pre[i] = pre[i - 1] ^ arr[i];
            }

            int ans = 0;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i; j < n - 1; j++)
                {
                    int right = 0,left=pre[j];
                    if(i>0)left^=pre[i-1];
                    
                    for (int k = j + 1; k < n; k++)
                    {
                        right ^= arr[k];
                        if (right == left) ans += 1;
                    }
                }
            }
            return ans;
        }
};