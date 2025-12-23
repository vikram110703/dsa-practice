class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return ans;
    }

    void solve(vector<int>& candidates, int target,int strt)
    {
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        if(target<2 || strt>=candidates.size()||target <candidates[strt])return;

           tmp.push_back(candidates[strt]);
           solve(candidates,target-candidates[strt],strt);

           tmp.pop_back();
           //not take this
           solve(candidates,target,strt+1);
    }

};