class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1,mid;
        while(h-l>1)
        {
            mid=l+(h-l)/2;
            if(arr[mid]>=arr[mid+1])
            {
                h=mid;
            }
            else //[mid+1]>[mid]
            {
                l=mid+1;
            }
        }
        if(arr[h]>arr[l])return h;
        return l;
        
    }
};