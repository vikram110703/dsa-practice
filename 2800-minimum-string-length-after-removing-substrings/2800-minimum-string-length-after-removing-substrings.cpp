class Solution {
public:
    int minLength(string s) {
        bool flg=true;
        while(flg)
        {
            int n=s.size();
            flg=false;
            for(int i=0;i<n-1;i++)
            {
                string ss="";
                ss+=s[i];
                ss+=s[i+1];
                if(ss=="AB"||ss=="CD")
                {
                    s.erase(i,2);
                    flg=true;
                    break;
                }
            }
        }
        return s.size();
    }
};