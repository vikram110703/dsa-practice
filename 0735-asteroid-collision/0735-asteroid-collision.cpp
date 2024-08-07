class Solution {
public:
    vector<int>asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        stack<int>tmp;
        int j=asteroids.size()-1;
        int i=0,jj=j;
        while(i<=j)
        {
            if(asteroids[i]<0)i+=1;
            else break;
        }
        while(j>=i)
        {
            if(asteroids[j]>0)j-=1;
            else break;
        }
        jj=j;
        while(j>=i)
        {
            if(st.size()==0)
            {
                st.push(asteroids[j]);
                j-=1;
            }
            else
            {
                if(st.top()*asteroids[j]>0)
                {
                    st.push(asteroids[j]);
                    j-=1;
                }
                else{
                    while(j>=0&&st.size()>0&&(st.top()*asteroids[j])<0)
                    {
                        if(abs(st.top())==abs(asteroids[j])&&st.top()<0)
                        {
                            st.pop();
                            j-=1;
                        }
                        else if(st.top()>0)
                        {
                            st.push(asteroids[j]);
                            j-=1;
                        }
                        else if(st.top()<0)//<-
                        {
                            if(asteroids[j]>abs(st.top())){
                                st.pop();
                            }
                            else{
                                j-=1;
                            }
                        }
                    }
                }
            }
        }
      
        vector<int>ans;
        i-=1;
        while(i>=0)ans.push_back(asteroids[i--]);
        reverse(ans.begin(),ans.end());
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        // reverse(ans.begin(),ans.end());
        jj+=1;
        while(jj<asteroids.size())ans.push_back(asteroids[jj++]);
        return ans;
    }
};