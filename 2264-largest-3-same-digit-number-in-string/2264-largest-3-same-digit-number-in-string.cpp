class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string ans="";
        for(int i=0;i<=n-3;i++){
            string s="";
            if(num[i]==num[i+1]&&num[i]==num[i+2]){
                s+=num[i];s+=num[i];s+=num[i];
            }
            if(s.size()>0&&ans.size()>0)ans=max(ans,s);
            else if(s.size()) ans=s;
        }
        return ans;
    }
};