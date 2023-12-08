class Solution {
public:
    int compress(vector<char>& chars) {
      string ans="";
        for(int i=0;i<chars.size();i++){
            int cnt=0;
            char curr=chars[i];
            while(i<chars.size()&&chars[i]==curr){
                cnt+=1;i+=1;
            }
            ans+=curr;
            if(cnt>1)ans+=(to_string(cnt));
            if(i==chars.size())break;
            else i-=1;
        }
        for(int i=0;i<ans.size();i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};