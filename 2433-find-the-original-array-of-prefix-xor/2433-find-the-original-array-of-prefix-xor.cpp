class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        int prevXor=pref[0];
        
        // again take prefix xor of array 
        for(int i=1;i<n;i++){
            int avlXor=prevXor;
            int reqXor=pref[i];
            int reqVal=0;
            
            reqVal=avlXor^reqXor;
            
            prevXor=pref[i];
            pref[i]=reqVal;
            
        }
        return pref;
        
    }
};