class Solution
{
    public:
//............FIND.....................................
        string find(string s, unordered_map<string, string> &parent)
        {
            if (parent[s] == s) return s;
            return parent[s] = find(parent[s], parent);
        }
//...........UNION.....................................
    void Union(string a, string b, unordered_map<string, string> &parent, unordered_map<string, int> &Size)
    {
        a = find(a, parent);
        b = find(b, parent);

        if (a != b)
        {
            if (Size[b] > Size[a]) swap(a, b);
            parent[b] = a;
            Size[a] += Size[b];
        }
    }

    vector<vector < string>> accountsMerge(vector<vector < string>> &accounts)
    {
        int n = accounts.size();
        unordered_map<string, int> Size;
        unordered_map<string, string> parent;
        map<pair<string, string>, set< string>> mpp;

        vector<vector<string>>ans;

       	// make Set
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                Size[accounts[i][j]] = 1;
                parent[accounts[i][j]] = accounts[i][j];
            }
        }
        
//  .............................................................       
         for (int i = 0; i < n; i++)
        {
//                 union every email
            for (int j = 1; j < accounts[i].size(); j++)
            {
                Union(accounts[i][j], accounts[i][1], parent, Size);
            }
            
        }
        //update parents after Union 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<accounts[i].size();j++)
            {
                parent[accounts[i][j]]=find(accounts[i][j],parent);
            }
        }
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string s=accounts[i][j];
                // if(j+1<n)s=accounts[i][j];
                mpp[{accounts[i][0], parent[accounts[i][1]]}].insert(accounts[i][j]);
            }
        }
        
        for(auto &it:mpp)
        {
            vector<string>tmp;
            tmp.push_back(it.first.first);
            for(auto &x:it.second)
            {
                tmp.push_back(x);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        
        return ans;
    }
};