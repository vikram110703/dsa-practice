class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        unordered_map<int,char>mpp,tmp;
        int cnt=0,flg=0;
        for(int i=0;i<n;i++)
        {
            while( mpp[s[i]]==0 &&i<n)
            {
                mpp[s[i]]+=1;i+=1;
            }
            if(i==n){cnt+=1;break;}
            cnt+=1;
            i-=1;
            mpp=tmp;
        }
        return cnt;
        
    }
};