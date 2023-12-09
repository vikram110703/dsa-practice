class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,maxi=0,n=nums.size(),k=1;
        while(i<nums.size()&&j<nums.size()){
            while(i<n&&k>=0){
                if(nums[i]==0){
                    k-=1;
                }
                if(k<0)break;
                i+=1;
            }
            int cnt=i-j;
            maxi=max(maxi,cnt);
            while(j<=i&&k<0){
                if(nums[j]==0)k+=1;
                j+=1;
                if(k==0)i+=1;
            }
        }
        maxi=max(maxi-1,0);
        return maxi;
    }
   
};