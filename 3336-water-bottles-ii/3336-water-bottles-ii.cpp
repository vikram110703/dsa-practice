class Solution {
public:
    int maxBottlesDrunk(int full , int ex) {
        int ans=0,empty=0;
        while(full>0){
            ans+=full;
            empty+=full;
            full=0;
            int exchange=0;
            if(empty>=ex){
                exchange+=ex;
                empty-=ex;
                ex+=1;
                full+=1;
            }
        }

        return ans;
        
    }
};