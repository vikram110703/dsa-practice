class Solution {
public:
    vector<int>parent;

    int findPar(int x)
    {
        if(parent[x]==x)return x;
        return findPar(parent[x]);
    }

    void dsu(int i,int j)
    {
        int ii=findPar(i);
        int jj=findPar(j);

        if(ii==jj)return;
        parent[jj]=ii;//
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                {
                    dsu(i,j);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)count+=1;
        }

        return n-count;
    }
};