class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size(),m=nums2.size();
        vector<int>ans;
        int i=0,j=0;
        while(i<n&&j<m)
        {
            while(i<n&&j<m&&nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i+=1;j+=1;
            }
            if(i<n&&j<m&&nums1[i]<nums2[j])i+=1;
            else j+=1;
        }
        return ans;
    }
};