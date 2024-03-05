class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
         int n=tokens.size();
        multiset<int>st;
        for(int i=0;i<n;i++){
            st.insert(tokens[i]);
        }
        
        int score=0,maxi=0;
        while(!st.empty()){
            int low=*st.begin();
            if(st.size()==1){
                if(low<=power){
                    score+=1;maxi=max(maxi,score);
                    break;
                }
            }
            if(low<=power){
                score+=1;
                power-=low;
                st.erase(st.begin());
                maxi=max(maxi,score);
            }
            else{
                int high=*(--st.end());
                power+=high;
                if(score>=1)
                score-=1;
                else{
                    break;
                }
                
                st.erase(--st.end());
            }
            
        }
        return maxi;
        
    }
};