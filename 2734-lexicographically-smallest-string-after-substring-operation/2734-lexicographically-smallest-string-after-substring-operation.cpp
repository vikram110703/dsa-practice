class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        bool chk=false;
        for(int i=0;i<n;i++){
            
        while(s[i]>='b'){
            s[i]-=1;
            i+=1;
            chk=true;
         }
            if(chk)break;
       }
        if(chk==false){
            s[n-1]='z';
        }
        
        return s;
        
    }
};