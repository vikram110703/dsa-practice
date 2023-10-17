class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        vector<int>inDeg(n);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                inDeg[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                inDeg[rightChild[i]]++;
                adj[i].push_back(rightChild[i]);
            }
        }
//TOPO
        queue<int>q;
        bool ans=true;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
            if(inDeg[i]>1){
                ans=false;break;
            }
        }
        if(ans==false)return false;
        // if tree is  discontinues or exist in  parts 
        if(q.size()!=1)return false;
        vector<int>vv;
        while(!q.empty()){
            int node=q.front();
            vv.push_back(node);
            q.pop();
            for(auto &child:adj[node]){
                inDeg[child]--;
                if(inDeg[child]==0){
                    // cout<<child<<" ";
                    q.push(child);
                }
            }
        }
        // cout<<endl;
        if(vv.size()!=n)ans=false;
        for(auto it:vv)cout<<it<<" ";
        return ans;
        
    }
};