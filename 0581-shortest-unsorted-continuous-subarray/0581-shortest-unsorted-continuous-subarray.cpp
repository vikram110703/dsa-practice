class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>tmp=nums;
        sort(tmp.begin(),tmp.end());
        int strt=0,end=0;
        bool first=false;
        for(int i=0;i<n;i++)
        {
            if(tmp[i]!=nums[i])
            {
                if(!first){first=true;strt=i;}
                else
                {
                    end=i;
                }
            }
        }
        return end==0?0:end-strt+1;
        
    }
};