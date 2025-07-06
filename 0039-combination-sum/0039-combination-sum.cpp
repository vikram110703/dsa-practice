class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0);
        return ans;
    }

    void solve(vector<int>& candidates, int target,int strt)
    {
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        if(target<2 ||strt>=candidates.size())return;

        for(int i=strt;i<candidates.size();i++){
           tmp.push_back(candidates[i]);
           solve(candidates,target-candidates[i],i);

           tmp.pop_back();//not take this
        }
    }

};