class Solution {
public:

    bool chk_palindrome(string s,int start,int end){
        
        while(end>=start){
            if(s[start]!=s[end])return false;
            else {
                start+=1;
                end-=1;
            }
        }
        return true;
    }

    void calculate(int start,string s,vector<vector<string>>&ans,vector<string>&tmp){
        if(start>=s.size()){
            ans.push_back(tmp);
            return;
        }

        for(int end=start;end<s.size();end++){
            string a=s.substr(start,end-start+1);

            if(chk_palindrome(s,start,end)){
                tmp.push_back(a);
                calculate(end+1,s,ans,tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tmp;

        calculate(0,s,ans,tmp);
        return ans;

    }

};