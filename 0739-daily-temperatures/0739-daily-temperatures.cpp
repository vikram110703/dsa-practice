class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;//store index
        int curr=temp.size()-1;
        vector<int>ans(temp.size(),0);
        for(int i=temp.size()-1;i>=0;i--){
            curr=temp[i];
            while(!st.empty()&&temp[st.top()]<=curr){
                st.pop();
            }
            if(st.empty())ans[i]=0;
            else ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};