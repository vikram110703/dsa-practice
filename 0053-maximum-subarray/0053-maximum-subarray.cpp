class Solution
{
    public:
        int maxSubArray(vector<int> &arr)
        {
            int n = arr.size();
            int maxSum = INT_MIN, curSum = 0;
            for (int i = 0; i < n; i++)
            {
                curSum += arr[i];
                maxSum = max(maxSum, curSum);
                if (curSum <= 0)
                {
                    curSum = 0;
                }
            }
              return maxSum;
        }
  
};