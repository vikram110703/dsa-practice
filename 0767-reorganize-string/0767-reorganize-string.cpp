class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        string ss="";
        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();
            pair<int,char>pp;
            
            if(pq.empty()){
                for(int i=0;i<p.first;i++){
                    char a=p.second;
                    ss+=a;
                    // cout<<ss<<" ";
                    // cout<<p.second<<" ";
                }
                break;
            }
            else{
                pp=pq.top();pq.pop();
            }
            ss+=p.second;p.first-=1;
            ss+=pp.second;pp.first-=1;
            if(p.first)pq.push(p);
            if(pp.first)pq.push(pp);
        }
        for(int i=0;i<ss.size();i++){
            if(i+1<n){
                if(ss[i]==ss[i+1]){
                    return "";
                }
            }
        }
        return ss;
    }
};