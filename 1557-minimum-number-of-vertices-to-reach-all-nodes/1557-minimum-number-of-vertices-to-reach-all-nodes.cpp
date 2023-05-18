class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int,bool>inDeg;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            inDeg[b]=true;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==false)ans.push_back(i);
        }
        return ans;
    }
};