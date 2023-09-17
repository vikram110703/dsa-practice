class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans(n+m,0);
        int i=0,j=0,k=0;
        while(k<m+n)
        {
            if(i<m&&j<n)
            {
                if(nums1[i]<nums2[j]){
                    ans[k++]=nums1[i++];
                }
                else//[i]>=[j]
                {
                    ans[k++]=nums2[j++];
                }
            }
            else{
                if(i<m){
                    ans[k++]=nums1[i++];
                }
                else {
                    ans[k++]=nums2[j++];
                }
            }
        }
        nums1=ans;
    }
};