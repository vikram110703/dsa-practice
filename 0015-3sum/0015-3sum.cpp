class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &v)
        {

            int n = v.size();
            sort(v.begin(), v.end());
            vector<vector < int>> ans;
            unordered_map<int,int>mpp;
            for(int i=0;i<n;i++)
            {
                mpp[v[i]]=i;
            }

            for (int i = 0; i < n-2; i++)
            {
                for (int j = i + 1; j < n-1; j++)
                {
                   int sum=v[i]+v[j];
                    if(mpp.count(-sum)&&mpp[-sum]>j)
                    {
                        ans.push_back({v[i],v[j],-sum});
                        j=mpp[v[j]];
                    }
                }
                i=mpp[v[i]];
            }

      
            return ans;
        }
};

/*HashMap Approach:

In this approach, firstly, we will hash the indices of all elements in a hashMap. In case of repeated elements, the last occurence index would be stored in hashMap.

Here also we fix a number (num[i]), by traversing the loop. But the loop traversal here for fixing numbers would leave last two indices. These last two indices would be covered by the nested loop.
If number fixed is +ve, break there because we can't make it zero by searching after it.
Make a nested loop to fix a number after the first fixed number. (num[j])
To make sum 0, we would require the -ve sum of both fixed numbers. Let us say this required.
Now, we will find the this required number in hashMap. If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet. Push it in answer vector.
Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
Update i to last occurence of 1st fixed number to avoid duplicate triplets.
Return answer vector.  

 */