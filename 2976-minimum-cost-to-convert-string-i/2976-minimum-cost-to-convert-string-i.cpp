const long long inf=1e18;
class Solution {
public:
    
    void floyadWarshall(vector<vector<long long>>&dist){
        int n=dist.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j]&&(dist[i][k]!=inf&&dist[k][j]!=inf)){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long >>dist(26,vector<long long>(26,inf));
        int nn=original.size();
        
        for(int i=0;i<nn;i++){
            char orig=original[i];
            char chang=changed[i];
            long long  w=cost[i];
            dist[orig-'a'][chang-'a']=min(dist[orig-'a'][chang-'a'],w);
        }
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        floyadWarshall(dist);
        long long  minCost=0;
        for(int i=0;i<source.size();i++){
            long long dst=dist[source[i]-'a'][target[i]-'a'];
            if(dst==inf)return -1;
            minCost+=dst;
        }
        return minCost;
    }
};