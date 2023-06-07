class Solution {
public:
    int find(int n,vector<int>&parent)
    {
        if(parent[n]==n)return n;
        return parent[n]=find(parent[n],parent);
    }
    void Union(int a,int b,vector<int>&parent,vector<int>&Size,int &cnt)
    {
        a=find(a,parent);
        b=find(b,parent);
        if(a!=b)
        {
            cnt+=1;
            if(Size[b]>Size[a])swap(a,b);
            parent[b]=a;
            Size[a]+=Size[b];
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int>parent(n);
        vector<int>Size(n);
        // make set 
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            Size[i]=1;
        }
        int nn=connections.size();
        int cnt=0;//cables used
        for(int i=0;i<nn;i++)
        {
            int a=connections[i][0];
            int b=connections[i][1];
            Union(a,b,parent,Size,cnt);
        }
        // cout<<cnt<<endl;
        int remComp=n-(cnt+1),remCbl=nn-cnt;
        if(remComp<=remCbl){
            return remComp;
        }
        return -1;
        
        
    }
};