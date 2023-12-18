class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int curr=spells[i];
            long long req=(success/curr);
            if(success%curr>0)req+=1;
            auto it=lower_bound(potions.begin(),potions.end(),req)-potions.begin();
            int count=m-it;
            spells[i]=count;
        }
        return spells;
        
    }
};