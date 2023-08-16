class Solution {
public:
    
    
void build(int ind, int low, int high, vector<int> &a, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid, a, seg);
    build(2 * ind + 2, mid + 1, high, a, seg);
    seg[ind] = max(seg[(2 * ind) + 1],seg[(2 * ind) + 2]);
}

int query(int ind, int low, int high, int l, int r, vector<int> &seg)
{
    if (high < l || low > r)
        return INT_MIN;
    if (low >= l && high <= r)
        return seg[ind];
    int mid = low + (high - low) / 2;
    int left = query((2 * ind) + 1, low, mid, l, r, seg);
    int right = query((2 * ind) + 2, mid + 1, high, l, r, seg);
    return max(left,right);
}
    
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int>seg(4*n,0),ans;
        build(0,0,n-1,a,seg);
        int strt=0;
        for(int i=k-1;i<n;i++)
        {
            int maxi=query(0,0,n-1,strt,i,seg);
            // cout<<strt<<" "<<k<<endl;
            ans.push_back(maxi);
            strt++;
        }
        return ans;
       
    }
};