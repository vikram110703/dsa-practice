class Solution {
public:
    //int to binary
    string chk(int a)
    {
        string s="";
       for(int i=0;i<32;i++)
       {
           if((a>>i)&1)
           {
               s+='1';
           }
           else s+='0';
       }
        reverse(s.begin(),s.end());
        return s;
        
    }
    
    int minFlips(int a, int b, int c) {
        
        string aa=chk(a);
        string bb=chk(b);
        string cc=chk(c);
        // cout<<aa<<" "<<bb<<" "<<cc<<endl;
        
        int cnt=0;
        for(int i=0;i<min(aa.size(),bb.size());i++)
        {
            if(cc[i]=='1')
            {
                if(aa[i]=='0'&&bb[i]=='0')cnt+=1;
        
            }
            else {
                if(aa[i]=='1')cnt+=1;
                if(bb[i]=='1')cnt+=1;
            }
        }
        return cnt;
        
    }
};