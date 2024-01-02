class Solution {
public:
    int romanToInt(string s) {
        map<string,int>mpp;
        mpp["I"]=1;
        mpp["V"]=5;
        mpp["X"]=10;
        mpp["L"]=50;
        mpp["C"]=100;
        mpp["D"]=500;
        mpp["M"]=1000;
        
        //ONLY THESE COMBO CAN BE POSSIBLE
         mpp["IV"]=4;
         mpp["IX"]=9;
         mpp["XL"]=40;
         mpp["XC"]=90;
         mpp["CD"]=400;
         mpp["CM"]=900;
        
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            string ss="";
            while(i<n){
                ss+=s[i];
                if(!mpp.count(ss)){
                    ss.erase(--ss.end());
                    break;
                }
                i+=1;
            }
            ans+=mpp[ss];
            if(i==n)break;
            else i-=1;
        }
        
        return ans;
    }
};