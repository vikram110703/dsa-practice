class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,maxi=0,n=nums.size();
        while(i<nums.size()&&j<nums.size()){
            while(i<n&&k>=0){
                if(nums[i]==0)k-=1;
                if(k<0)break;
                i+=1;
            }
            // cout<<i<<" "<<j<<"  ";
            maxi=max(maxi,i-j);
            while(j<=i&&k<0){
                if(nums[j]==0)k+=1;
                j+=1;
                if(k==0)i+=1;
            }
            // cout<<i<<" "<<j<<endl;
        }
        // cout<<i<<" "<<j<<endl;
        return maxi;
    }
};