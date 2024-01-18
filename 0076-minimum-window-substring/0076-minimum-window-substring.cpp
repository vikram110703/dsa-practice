class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mpp(128,0);
        for(auto &it:t)mpp[it]++;
        int strt=0,end=0,head=0,d=INT_MAX,cnt=t.size();
        while(end<s.size()){
            if((mpp[s[end++]]--)>0)cnt-=1;//valid char
            while(cnt==0){
                if(end-strt<d){
                    head=strt;
                    d=end-strt;
                }
                 if((mpp[s[strt++]]++)==0)cnt+=1;//invalid char
            }
            
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};