class Solution {
public:
    int possibleStringCount(string word) {
       int ans=1;
       int i=0,n=word.size();
       for(int i=0;i<n;i++)
       {
            int j=i+1;
            while(j<n && (word[i]==word[j])){
                j+=1;
                ans+=1;
            }
            i=j-1;
       }
       return ans;
    }
};