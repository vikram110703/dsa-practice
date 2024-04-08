class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt=0,cntt=0;
        queue<int>q;
        stack<int>st;
        int n=students.size();
        for(int i=0;i<n;i++){
            if(students[i]==1)cnt+=1;
            if(sandwiches[i]==1)cntt+=1;
            q.push(students[i]);
            st.push(sandwiches[n-1-i]);
        }
        while(q.size()>0&&st.size()>0){
            int student=q.front();
            int sand=st.top();
            if(cnt==q.size()&&sand==0)break;
            if(cnt==0&&sand==1)break;
            if(student==sand){
                q.pop();
                st.pop();
                cnt-=(student==1);
                cntt-=(sand==1);
            }
            else{
                q.pop();
                q.push(student);
            }
        }
        
        return q.size();
        
        
    }
};