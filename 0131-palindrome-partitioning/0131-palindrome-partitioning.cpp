class Solution {
public:
    bool isPalindrome(string s,int strt,int end){
        while(end>strt){
            if(s[strt]!=s[end])return false;
            strt+=1;end-=1;
        }
        return true;
    }
    
    void f(int ind,string s,vector<string >&tmp,vector<vector<string>>&ans)
    {
        if(ind==s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i))
            {
                tmp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,tmp,ans);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tmp;
        f(0,s,tmp,ans);
        return ans;
        
    }
};