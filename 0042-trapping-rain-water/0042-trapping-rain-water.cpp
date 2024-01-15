class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n,0),rightMax(n,0);
        
        for(int i=1;i<n;i++)leftMax[i]=max(leftMax[i-1],height[i-1]);
        for(int i=n-2;i>=0;i--)rightMax[i]=max(rightMax[i+1],height[i+1]);
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=min(leftMax[i],rightMax[i]);
            if(mini>height[i])ans+=mini-height[i];
        }
        return ans;
    }
    
};