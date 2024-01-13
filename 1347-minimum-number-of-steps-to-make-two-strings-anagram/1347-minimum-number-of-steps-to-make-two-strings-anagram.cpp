class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>v(26,0);
        for(int i=0;i<t.size();i++)v[s[i]-'a']++;
        for(int i=0;i<t.size();i++){
            v[t[i]-'a']--;
        }
        int cnt=0;
        for(int i=0;i<26;i++)if(v[i]>0)cnt+=v[i];
        return cnt;
    }
};