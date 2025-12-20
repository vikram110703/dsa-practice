class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // using divede opr. approach will fail when we encounter an zero in array 
        // we can use preMult and SuffMul array to get our ans ans[i]=pre[i-1]*[pre[i+1]]
        
        // now in O(1) , same approach 
        int curr=1;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=curr;
            curr*=nums[i];
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=curr;
            curr*=nums[i];
        }
        return ans;
    
    }
};