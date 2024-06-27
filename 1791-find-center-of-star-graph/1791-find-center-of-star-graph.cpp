class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mpp;
        for(int i=0;i<edges.size();i++){
            mpp[edges[i][0]]+=1;
            if(mpp[edges[i][0]]>1)return edges[i][0];
            mpp[edges[i][1]]+=1;
            if(mpp[edges[i][1]]>1)return edges[i][1];
        }
        // do nothing
        return 1;
    }
};