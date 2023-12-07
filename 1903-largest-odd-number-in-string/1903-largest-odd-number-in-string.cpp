class Solution {
public:
    string largestOddNumber(string num) {
        int strt=0,end=-1;
        int n=num.size();
        for(int i=n-1;i>=0;i--){
             if((num[i]&1)==1){
                end=i;break;
            }
        }
        string ans=num.substr(strt,end-strt+1);
        return ans;
    }
};