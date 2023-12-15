class Solution {
public:
    map<string,string>adj;
    string last;
    void dfs(string node){
            if(!adj.count(node))return;
            string a=adj[node];
            last=a;
            dfs(a);
    }
    
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        for(int i=0;i<n;i++){
            string a=paths[i][0];
            string b=paths[i][1];
            adj[a]=b;
        }
        dfs(paths[0][0]);
        return last;
        
    }
};