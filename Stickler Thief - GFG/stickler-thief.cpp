//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int chk(int ind, int arr[],int n, vector<int>& dp)
    {
        if (ind >= n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int pick = -1, notPick = -1;
        notPick = chk(ind + 1, arr,n, dp);
      
        pick = arr[ind]+chk(ind + 2, arr, n, dp);

        dp[ind] = max(pick, notPick);
        return dp[ind];
    }

    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 1, -1);
        int result = chk(0, arr, n, dp);
        return result;
    }

};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends