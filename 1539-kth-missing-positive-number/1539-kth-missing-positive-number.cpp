class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int n = arr.size();
           	//  checking missing elemetns before arr[0]
            int strt = arr[0] - 1;
           	//kth missing element is > arr[0]
            if (k >= strt)
            {
                k -= strt;
            }
           	// kth missing element is < arr[0]
            else
            {
                return k;
            }
            if (k == 0) return strt;

           	//  checking Kth missing element in the range[arr[0],arr[n-1]]
            for (int i = 0; i < n - 1; i++)
            {

                if (arr[i + 1] - arr[i] > 1)
                {
                   	//total missing elements between arr[i]--arr[i+1]
                    int missing = arr[i + 1] - arr[i]-1;
                   	//missing is >=k
                    if (missing >= k)
                    {
                        return arr[i] + k;
                    }
                    else
                    {
                        k -= missing;
                    }
                }
            }

           	// if missing element is >arr[n-1]
            int last = arr[n - 1] + (k);
            return last;
        }
};