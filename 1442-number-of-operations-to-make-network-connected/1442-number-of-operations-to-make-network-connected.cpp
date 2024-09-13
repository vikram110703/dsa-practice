class Solution {
public:

    vector<int>parent;
    vector<int>size;

    int findPar(int a)
    {
        if(a==parent[a])return a;
        return parent[a]=findPar(parent[a]);
    }

    void DSU(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);

        if(a==b)return;

        if(size[a]>=size[b])
        {
            parent[b]=a;
            size[a]+=size[b];
        }
        else
        {
            parent[a]=b;
            size[b]+=size[a];
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.resize(n);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;//initializing 
            size[i]=1;
        }

        int available_cables=0;// store the extracted cables

        for(auto &it:connections)
        {
            int a=findPar(it[0]);
            int b=findPar(it[1]);

            if(a==b)available_cables+=1;//already connected 
            else
            {
                DSU(a,b);
            }
        }
        
        int req_cables=0;
        set<int>st;

        for(int i=0;i<n;i++)
        {
               st.insert(findPar(i));  
        }

        req_cables=st.size()-1;

        cout<<available_cables<<" "<<req_cables<<endl;
        if(available_cables>=req_cables)
        {
            return req_cables;
        }
        else
        {
            return -1;
        }
    }
};