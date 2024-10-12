class Solution {
public:

    int minGroups(vector<vector<int>>& intervals) {

        vector<int>diffArr(1000005,0);
        for(auto &it:intervals)
        {
            int l=it[0];
            int r=it[1];

            diffArr[l]+=1;
            diffArr[r+1]-=1;
        }  

        int groups=0;

        for(int i=1;i<diffArr.size();i++)
        {
            diffArr[i]+=diffArr[i-1];
            groups=max(groups,diffArr[i]);
        }

        return groups;
    }
};