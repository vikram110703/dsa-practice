class Solution {
public:
    int evalRPN(vector<string>& ss) {
        //size
            int n=ss.size();
            stack< long long>st;
            string s=ss[0];
             long long  pre=stoi(s),top;
            for(int i=0;i<n;i++)
            {
                 s=ss[i];
                if((s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')&&(s.size()==1))
                {
                  
                    top=st.top();
                    st.pop();
                    pre=st.top();
                    st.pop();
                    if(s[0]=='+')
                    {
                        pre+=top;
                    }
                    else if(s[0]=='-')
                    {
                        pre-=top;
                    }
                    else if(s[0]=='*')
                    {
                        pre*=top;
                    }
                    else if(s[0]=='/')
                    {
                        pre/=top;
                    }
                    st.push(pre);

                }
                else
                {

                 st.push(stoi(s));   
                    
                }
            }
        // cout<<"done"
            return pre;
        
    }
};