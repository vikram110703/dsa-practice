class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obst) {
        int n=obst.size();
        vector<int>ans(n,1),pre;
        //in pre ,we are stroing the minimum ending point of length(i+1);
        int indx;
        for(int i=0;i<n;i++)
        {
            auto it=upper_bound(pre.begin(),pre.end(),obst[i])-pre.begin();
            indx=it;
            if(it==pre.size())pre.push_back(obst[i]);//push new 
            else
            {
                pre[indx]=obst[i];//update pre
            }
            ans[i]=indx+1;
        }
        return ans;
        
    }
};