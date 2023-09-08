class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>v;
        if(n==1)return {{1}};
        if(n==2)return{{1},{1,1}};
        v.push_back({1});
        v.push_back({1,1});
        for(int i=2;i<n;i++)
        {
            vector<int>tmp;
            tmp.push_back(1);
            for(int j=0;j<i-1;j++)
            {
                tmp.push_back(v[i-1][j]+v[i-1][j+1]);
            }
            tmp.push_back(1);
            v.push_back(tmp);
        }

        return v;
    }
};