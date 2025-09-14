class Solution {
public:
    int countDiff(string tmp,string &s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=tmp[i])cnt++;
        }
        return cnt;
    } 

    int minSwaps(string s) {
        int one=0,zero=0,o=0,z=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')one+=1;
            else zero+=1;
        }
        if(abs(one-zero)>1)return -1;// not possble
        //101010101... or 01010101.... only two possible arrangment
        string op="",opp="";
        o=one,z=zero;
        while(o>0 || z>0){
            if(op.size()==0||op.back()=='0'){
                if(one==0)break;
                op+='1';o-=1;
            }
            else{
                if(z==0)break;
                op+='0';z-=1;
            }
        }
        o=one,z=zero;
        while(o>0 || z>0){
            if(opp.size()==0||opp.back()=='1'){
                if(z==0)break;
                opp+='0';z-=1;
            }
            else{
                if(one==0)break;
                opp+='1';o-=1;
            }
        }
        int ans=INT_MAX;
        if(op.size()==n){
            ans=min(ans,countDiff(op,s));
        }
        if(opp.size()==n){
            ans=min(ans,countDiff(opp,s));
        }
        return ans==INT_MAX?-1:(ans+1)/2;
    }
};

