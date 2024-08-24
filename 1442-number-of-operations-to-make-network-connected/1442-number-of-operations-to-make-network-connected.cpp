class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    void Union(int u,int v)
    {
        // finding the ultimate parent
        int ulPar_u=findUlPar(u);
        int ulPar_v=findUlPar(v);

        if(ulPar_u==ulPar_v) return ;//base case

        if(rank[ulPar_u]>rank[ulPar_v])
        {
            parent[ulPar_v]=ulPar_u;
        }
        else if(rank[ulPar_v]>rank[ulPar_u])
        {
            parent[ulPar_u]=ulPar_v;
        }
        else// same rank
        {
            parent[ulPar_v]=ulPar_u;
            rank[ulPar_u]+=1;
        }
    }

    int findUlPar(int u)
    {
        if(parent[u]==u)return u;

        return parent[u]=findUlPar(parent[u]);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // n-> : total computers

        parent.resize(n,0);
        rank.resize(n,0);

        //initializing parent and rank
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }

        int available_cables=0;

        for(auto &adj:connections)
        {
            int u=findUlPar(adj[0]);
            int v=findUlPar(adj[1]);

            if(u==v)// already connected
            {
                available_cables+=1;//extract this cable
            }
            else
            {
                Union(u,v);// connect them
            }
        }

        set<int>st;

        for(int i=0;i<n;i++)
        {
           st.insert(findUlPar(i));
        }

        int totalGroups=st.size()-1;

        return available_cables >= totalGroups ? totalGroups : -1 ;
    }
};