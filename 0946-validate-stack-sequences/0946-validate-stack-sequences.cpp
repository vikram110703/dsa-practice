class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>st;
        int j=0,i=0;
        while(true)
        {
            // if(i==n&&j<n&&st.top()!=popped[j])break;
            if(st.size()==0){st.push(pushed[i++]);}
         
                if(popped[j]==st.top())
                {
                    while(j<n&&st.size()>0&&popped[j]==st.top())
                    {
                        st.pop();
                        ++j;
                    }
                    if(i>=n&&j>=0)break;
                }
            if(i<n) {st.push(pushed[i++]);}// to handle case when we pushed all the elements in stack 
            else break;
            
        }
        return st.empty()==true?true:false;
        
    }
};