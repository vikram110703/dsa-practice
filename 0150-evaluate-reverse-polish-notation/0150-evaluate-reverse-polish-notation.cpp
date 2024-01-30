class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &it:tokens){
            char a=it[0];
            if(a=='+'){
                int aa=st.top();
                st.pop();
                int bb=st.top();
                st.pop();
                st.push(aa+bb);
            }
            else if(a=='-'&&it.size()==1){
                int aa=st.top();
                st.pop();
                int bb=st.top();
                st.pop();
                st.push(bb-aa);
            }
            else if(a=='*'){
                int aa=st.top();
                st.pop();
                int bb=st.top();
                st.pop();
                st.push(bb*aa);
            }
            else if(a=='/'){
                 int aa=st.top();
                st.pop();
                int bb=st.top();
                st.pop();
                st.push(bb/aa);
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};