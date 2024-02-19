class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        n=abs(n);
        int setBit=log2(n); 
        return pow(2,setBit)==n?true:false;
    }
};