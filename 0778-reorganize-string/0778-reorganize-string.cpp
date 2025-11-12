class Solution {
public:
    string reorganizeString(string s) {
        vector<int>v(26,0);// char->freq;
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']+=1;
        }
        //max-heap
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        for(int i=0;i<26;i++){
            if(v[i]>0){
                pq.push({v[i],i+'a'});
            }
        }

        string ans="";
        while(pq.size()>1){
            pair<int,char>first=pq.top();
            pq.pop();
            pair<int,char>second=pq.top();
            pq.pop();
            // cout<<first.first<<" "<<first.second<<endl;
            // cout<<second.first<<" "<<second.second<<endl;
            ans+=first.second;
            ans+=second.second;

            first.first-=1;
            second.first-=1;
            if(first.first>0)pq.push(first);
            if(second.first>0)pq.push(second);
        }

        if(pq.size()>0){
            pair<int,char>ff=pq.top();
            pq.pop();
            if(ff.first==1){
                ans+=ff.second;
            }
            else return "";
        }

        return ans;

    }
};