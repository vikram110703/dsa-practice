class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>>vp;
        for(int i=0;i<boxTypes.size();i++){
            vp.push_back({boxTypes[i][1],boxTypes[i][0]});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        int ans=0;

        int i=0;
        while(truckSize>0 && i<vp.size()){
            int avlBox=vp[i].second;
            int perBox=vp[i].first;
            if(truckSize>=avlBox){
                truckSize-=avlBox;
                ans+=(perBox*avlBox);
            }
            else{
                ans+=(truckSize*perBox);
                truckSize=0;
            }
            i+=1;
        }
        return ans;
    }
};