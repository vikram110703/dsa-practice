class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &a,int &b)
        {
           string aa=to_string(a);
           string bb=to_string(b);

           string tmp1=aa+bb;
           string tmp2=bb+aa;

           return tmp1>tmp2;
        });//custom sorting function 

        string ans="";
        for(auto &it:nums)
        {
            string tmp=to_string(it);
            ans+=tmp;
        }

        int i=0;
        while(i<ans.size()&&ans[i]=='0')i+=1;
        if(ans[0]=='0')ans.erase(0,i+1);
        if(ans=="")ans="0";//if all chars are '0' : 000000->0 only
        
        return ans;
    }
};