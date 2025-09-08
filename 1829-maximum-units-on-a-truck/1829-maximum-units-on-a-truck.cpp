class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        int ans=0;
        int i=0;

        while(truckSize>0 && i<boxTypes.size()){
            int avlBox=boxTypes[i][0];
            int perBox=boxTypes[i][1];
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