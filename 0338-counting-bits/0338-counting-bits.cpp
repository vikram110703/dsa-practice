class Solution {
public:
    int count(int n){
        int cnt=0;
        for(int i=0;i<32;i++){
            if((n&(1<<i))>0)cnt+=1;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int cnt=count(i);
            ans.push_back(cnt);
        }
        return ans;
    } 
};