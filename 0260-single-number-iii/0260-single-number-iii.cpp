class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        int n=nums.size();
        for(int i=0;i<n;i++)xorr^=nums[i];
        // {a,b}  a^b=xorr
        //  we have to find a,b 
        
// now we will find the bit where a and b are differ means that bit in a^b or (xorr) wil be 1 coz. 1^0=1 0^1=1. It is given that both numbers are not same so we will get 1 such bit for sure .
    int i=0;
        while(((xorr>>i)&1)==0){
            i+=1;
        }
        
// ith bit is differ 
         int a=0,b=0;
    for(auto it:nums){
        // ith bit is 1 
        if((it>>i)&1)a^=it;
        else b^=it;
    }
    return {a,b};
        
    
          
    }
};