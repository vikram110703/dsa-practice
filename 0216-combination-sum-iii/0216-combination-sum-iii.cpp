class Solution {
public:
    vector<vector<int>>ans;
    
    void cal(int i,int n,int k,vector<int>tmp,int currSum){
        if(tmp.size()==k||i>9){
            if(tmp.size()==k&&currSum==n){
                ans.push_back(tmp);
            }
            return ;
        }
        if(i+currSum<=n){
            if(find(tmp.begin(),tmp.end(),i)==tmp.end()){
                tmp.push_back(i);
                cal(i+1,n,k,tmp,currSum+i);
                //backTrack
                tmp.pop_back();
            }
            cal(i+1,n,k,tmp,currSum);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>tmp;
        cal(1,n,k,tmp,0);
        return ans;
    }
};