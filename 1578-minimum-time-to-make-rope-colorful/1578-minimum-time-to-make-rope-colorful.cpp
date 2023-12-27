class Solution {
public:
    multiset<int>st;
    int ans=0;
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        char prev=colors[0];
        for(int i=0;i<n;i++){
            st.clear();
            while(i<n&&colors[i]==prev){
                st.insert(neededTime[i]);
                i+=1;
            }
            while(st.size()>1){
                ans+=(*st.begin());
                st.erase(st.begin());
            }
            if(i<n){
                prev=colors[i];
                i-=1;
            }
        }
       return ans;
    }
};