class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        
        unordered_map<char,int>mpp;
        int n=order.length();
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            mpp[order[i]]=cnt;
            cnt+=1;
        }
        
        n=words.size();
        bool flg=true;
        for(int i=0;i<n-1;i++)
        {
            string s=words[i];
            string ss=words[i+1];
            bool chk=true;
            int j=0;
            bool same=true;
            int mini=min(s.size(),ss.size());
         for(j;j<mini;j++)
         {
             while(mpp[s[j]]==mpp[ss[j]]&&j<mini)
             {
                 j+=1;
             }
             if(mpp[s[j]]>mpp[ss[j]]&&j<mini)
             {
                 same=false;
                chk=false;
                 break;
             }
             else if(mpp[ss[j]]>mpp[s[j]]&&j<mini)
             {
                 same=false;
                 chk=true;
                 break;
             }
             
         }
            // cout<<j<<endl;
            
                if(same==true&&(s.size()>ss.size()))chk=false;
            
            if(chk==false)
            {
                flg=false;
                break;
            }
            
        }
        return flg;
        
    }
};