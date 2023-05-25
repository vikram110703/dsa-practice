//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

        bool chk(vector<vector<int>>&dp,int t,int ind,vector<int>&arr)
        {
            if(ind==0)return arr[0]==t;
            if(t==0)return true;
            if(dp[ind][t]!=-1)return dp[ind][t];
            bool notPick=chk(dp,t,ind-1,arr);
            bool pick=false;
            if(arr[ind]<=t)pick=chk(dp,t-arr[ind],ind-1,arr);
            return dp[ind][t]=pick|notPick;
        }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return chk(dp,sum,n-1,arr);
        
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends