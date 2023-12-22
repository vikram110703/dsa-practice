class Solution {
public:
    int maxScore(string s) {
        int zeroInLeft=0,maxi=0;
        int totalOne=0;
        for(int i=0;i<s.size();i++)if(s[i]=='1')totalOne+=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')zeroInLeft+=1;
            int oneInLeft=i+1-zeroInLeft;
            int oneInRight=totalOne-oneInLeft;
            int result=(zeroInLeft+oneInRight);
            maxi=max(maxi,result);
        }
        return maxi;
    }
};