class Solution {
public:
    vector<int> getRow(int ind) {
         vector<int>prev;
        prev.push_back(1);
        if(ind==0)return prev;
        prev.push_back(1);
        if(ind==1)return prev;
        for(int i=2;i<=ind;i++)
        {
            vector<int>ans;
            int n=prev.size();
            for(int i=0;i<n;i++)
            {
                if(i==0)ans.push_back(1);
                else{
                    ans.push_back(prev[i]+prev[i-1]);
                }
            }
            ans.push_back(1);
            prev=ans;
        }
        return prev;
        
    }
};