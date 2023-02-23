// #include<bits/stdc++.h>
// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
//              int n=p.size();
//         vector<pair<int,int>>st;
        
//         for(int i=0;i<n;i++)
//         {
//             st.push_back({c[i],p[i]});
//         }
//         sort(c.begin(),c.end());
//         for(int i=0;i<n;i++)
//         {
//             p[i]=st[i].second;
//         }
        
//         int ans=0;
//         while(true)
//         {
//             auto it=upper_bound(c.begin(),c.end(),w)-c.begin();
//             if(it>0&&k>0)
//             {
//                 cout<<"it -> "<<it<<endl;
//                 auto itt=it-1;
//                 // w+=(c[itt]);
                
//                 auto new_it=max_element(p.begin(),p.begin()+itt);
//                 // cout<<"new_it-> "<<new_it<<endl;
//                 // cout<<"c-> "<<<<endl;
//                 ans+=*new_it;
//                 int ind=(p.begin()+new_it);
//                 w+=c[ind];
//                 cout<<"p-> "<<*new_it<<endl;
//                 // auto nn=(c.begin()+new_it);
//                 // c.erase(nn);
//                 // auto 
//                 p.erase(new_it);
//                 k-=1;
//             }
//             else break;
//         }
//         return ans;
           
        
//     }
// };



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int,int>> st;
        
        for(int i = 0; i < n; i++) {
            st.push_back({c[i], p[i]});
        }
        sort(st.begin(), st.end()); // Sort by capital
        
        int ans = w;
        int i = 0;
        priority_queue<int> pq; // Max heap to store profits
        
        while (k--) {
            while (i < n && st[i].first <= ans) {
                pq.push(st[i].second);
                i++;
            }
            if (pq.empty()) break; // Cannot invest further
            
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
