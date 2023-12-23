class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mpp;
        mpp[{0,0}]+=1;
        int x=0,y=0;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N')y+=1;
            if(path[i]=='E')x+=1;
            if(path[i]=='S')y-=1;
            if(path[i]=='W')x-=1;
            // cout<<x<<" "<<y<<" ";
           mpp[{x,y}]+=1;
            if(mpp[{x,y}]>1)return true;
        }
        return false;
    }
};