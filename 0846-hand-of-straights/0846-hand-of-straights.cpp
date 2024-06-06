class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        int n=hand.size();
        multiset<int>st;
        for(int i=0;i<n;i++){
            st.insert(hand[i]);
        }
        bool flag=true;
        while(st.size()>0 &&flag){
            auto it=st.lower_bound(0);
            int val=*it;
            st.erase(it);
            val+=1;
            for(int i=0;i<sz-1;i++){
                if(st.size()==0){
                    flag=false;
                    return false;
                }
                auto itt=st.lower_bound(val);
                if(itt==st.end()){
                    flag=false;
                    return false;
                }
                else{
                    if(*itt==val){
                        st.erase(itt);
                        val+=1;
                    }
                    else{
                        flag=false;
                        return false;
                    }
                }
            }
        }
        return flag;
        
    }
};