class Solution {
public:
    // l->(
    // r->) 
    int nn;
    void chk(int ind,int l,int r,vector<string>&ans,string &s){
        if(ind>=2*nn){
            if(l==r)
            ans.push_back(s);
            return;
        }
        if(l>r){
            s+='(';
            chk(ind+1,l+1,r,ans,s);
            s.pop_back();
            s+=')';
            chk(ind+1,l,r+1,ans,s);
            s.pop_back();
            
        }
        else if(l==r){
            s+='(';
            chk(ind+1,l+1,r,ans,s);
            s.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        nn=n;
        string s="";
        vector<string>ans;
        chk(0,0,0,ans,s);
        return ans;
    }
};