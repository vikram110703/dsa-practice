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